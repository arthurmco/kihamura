#include "gui-main.hpp"

struct {
    GtkBuilder* builder;
    GtkWidget* winMain;
} widgets;

static int gui_app_activate(GtkApplication* app, gpointer data);

static constexpr char* GladeIFaceFile = DATA_DIR "/kihamura/interface.glade";

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

    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return 0;
}

static int gui_app_activate(GtkApplication* app, gpointer data)
{
    widgets.builder = gtk_builder_new_from_file(GladeIFaceFile);

    widgets.winMain = GTK_WIDGET(gtk_builder_get_object(widgets.builder, "winMain"));
    g_signal_connect (widgets.winMain, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_application_add_window(app, GTK_WINDOW(widgets.winMain));

    gtk_window_maximize(GTK_WINDOW(widgets.winMain));
    gtk_widget_show_all(widgets.winMain);

    gtk_main();
}
