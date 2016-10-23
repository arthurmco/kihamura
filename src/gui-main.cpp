#include "gui-main.hpp"

struct {
    GtkBuilder* builder;
    GtkWidget* winMain;

    GtkListStore* lsMedia;
} widgets;

struct {
    VideoProject* vp;
} data;

static int gui_app_activate(GtkApplication* app, gpointer data);
static void gui_setup_media_list();

static int gui_show_open_media_dialog(GtkMenuItem* mni, gpointer user_data);
static int gui_exit(GtkMenuItem* mni, gpointer user_data);
static int gui_insert_media(GSList* fileList);

static char const* GladeIFaceFile = DATA_DIR "/kihamura/interface.glade";

int gui_main(int argc, char** argv)
{
    /* Build the main application */
    GtkApplication* app;
    int status;

    /* TODO: Change to G_APPLICATION_HANDLES_CMDLINE (or something)
    as soon as we can handle them */
    app = gtk_application_new("com.github.arthurmco.kihamura",
        G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (gui_app_activate), NULL);


    data.vp = new VideoProject{"Untitled Project", 1280, 720, 30, 4096};

    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return 0;
}

static int gui_show_about_dialog(GtkMenuItem* mni, gpointer user_data)
{
    static const char* authors[] =
        {"Arthur Mendes <arthurmco@gmail.com>"};
    gtk_show_about_dialog(GTK_WINDOW(widgets.winMain),
        "program-name", "Kihamura",
        "comments", "a video editor designed to be easy to use",
        "version", "0.0.1",
        "authors", authors,
        "website", "http://github.com/arthurmco/kihamura",
        "website-label", "Github repo", NULL);
}

static int gui_app_activate(GtkApplication* app, gpointer data)
{
    /* Connect controls to events, then launch */

    widgets.builder = gtk_builder_new_from_file(GladeIFaceFile);

    widgets.winMain = GTK_WIDGET(gtk_builder_get_object(widgets.builder, "winMain"));
    g_signal_connect (widgets.winMain, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    GtkWidget* mniInsertMedia = GTK_WIDGET(gtk_builder_get_object(
        widgets.builder, "mniInsertMedia"));
    g_signal_connect(mniInsertMedia, "activate",
        G_CALLBACK(gui_show_open_media_dialog), NULL);

    GtkWidget* mniAbout = GTK_WIDGET(gtk_builder_get_object(
            widgets.builder, "mniAbout"));
    g_signal_connect(mniAbout, "activate",
            G_CALLBACK(gui_show_about_dialog), NULL);

    GtkWidget* mniExit = GTK_WIDGET(gtk_builder_get_object(
            widgets.builder, "mniExit"));
    g_signal_connect(mniExit, "activate",
            G_CALLBACK(gui_exit), NULL);

    gtk_application_add_window(app, GTK_WINDOW(widgets.winMain));

    gtk_window_maximize(GTK_WINDOW(widgets.winMain));
    gtk_widget_show_all(widgets.winMain);
    gui_setup_media_list();

    gtk_main();
}

enum TreeMediaColumnsIndex {
    TMC_MEDIANAME,
    TMC_COUNT,
};

static void gui_setup_media_list()
{
    widgets.lsMedia = GTK_LIST_STORE(gtk_builder_get_object(widgets.builder,
        "lsMedia"));
    GtkWidget* treeMedia = GTK_WIDGET(gtk_builder_get_object(widgets.builder,
        "treeMedia"));

    GtkCellRenderer* crMediaName =  gtk_cell_renderer_text_new ();
    GtkTreeViewColumn* colMediaName = gtk_tree_view_column_new_with_attributes(
        "Title", crMediaName, "text", TMC_MEDIANAME, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (treeMedia), colMediaName);
}

static int gui_exit(GtkMenuItem* mni, gpointer user_data)
{
    gtk_main_quit();
    exit(0);
}

static int gui_show_open_media_dialog(GtkMenuItem* mni, gpointer user_data)
{
    /*  Show an open media dialog.
        Adds it on the media list */

    GtkWidget* widOpenFile = gtk_file_chooser_dialog_new(
        "Add Media", GTK_WINDOW(widgets.winMain),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        _("_Cancel"), GTK_RESPONSE_CANCEL, _("_Open"), GTK_RESPONSE_ACCEPT,
        NULL);

    GtkFileChooser* widOpenChooser = GTK_FILE_CHOOSER(widOpenFile);
    gtk_file_chooser_set_select_multiple(widOpenChooser, TRUE);

    gint res = gtk_dialog_run(GTK_DIALOG(widOpenFile));
    if (res == GTK_RESPONSE_ACCEPT) {
        gui_insert_media(gtk_file_chooser_get_filenames(widOpenChooser));
    }
    gtk_widget_destroy(widOpenFile);
}

static int gui_insert_media(GSList* fileList)
{
    g_print("[GUI] Adding files...\n");

    Media* m;

    gchar* filename;
    while (fileList) {
        /* Check if media already exists */
        filename = (gchar*)fileList->data;
        g_print("\t%s", filename);

        MediaCollection::GetInstance()->ResetIterator();

        Media* it = nullptr;
        while (it = MediaCollection::GetInstance()->GetNext()) {
            if (!g_strcmp0(it->GetName(), filename)) {
                g_print(" (already exists) ");
                it = m;
            }
        }

        /* There's no media here */
        if (!it) {
            FileMedia* fm = new AnyMedia{filename};
            if (!fm->Open()) {
                g_error("\n\t %s failed to open!\n", filename);
                delete fm;
                continue;
            }
            m = fm;
            data.vp->GetMedia()->AddMedia(m);
        } else {
            m = it;
            data.vp->GetMedia()->CopyMedia(MediaCollection::GetInstance(),
                m);
        }

        /* Adds the media to the tree list */
        GtkTreeIter iter;
        gtk_list_store_append(widgets.lsMedia, &iter);
        gtk_list_store_set(widgets.lsMedia, &iter,
            TMC_MEDIANAME, m->GetName(), -1);


        g_print(" ok!\n");
        fileList = fileList->next;
    }
}
