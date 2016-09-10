/*
    Main file

    Copyright (C) 2016 Arthur M

*/

#include <cstdio>
#include <cstring>

#include "VideoProject.hpp"
#include "VideoTrack.hpp"

#define CMD_IS(line, cmd) \
    (!strcmp(line, cmd))

#define CHOMP(s)                        \
    do {                                \
        char* __z = strrchr(s, '\n');   \
        if(__z) *__z = 0;               \
    } while (0);    
    

int main(int argc, char **argv)
{
    VideoProject* vp = new VideoProject{"Test", 720, 480, 29.97f, 192000};
    printf("Project %s created\n", vp->GetName());
    printf("Size: %dx%d, %.2f fps, %.3f kbps of bitrate\n", 
        vp->GetWidth(), vp->GetHeight(), vp->GetFPS(), 
        vp->GetBitrate() / 1000.0f);
    
    
    bool exit=false;
    /* Temporary shell to configure projects */

    while (!exit) {
        printf("(kihamura) ");
        char line[128];
        fgets(line, 128, stdin);        

        /* Remove the newline character */
        CHOMP(line);
        
        if (CMD_IS(line, "info")) {
            printf("Project name: '%s'\n", vp->GetName());
            printf("Size: %dx%d, %.2f fps, %.3f kbps of bitrate\n", 
                vp->GetWidth(), vp->GetHeight(), vp->GetFPS(), 
                vp->GetBitrate() / 1000.0f);
        }

        if (CMD_IS(line, "exit")) {
            exit = true;
            break;
        }

        if (CMD_IS(line, "setname")) {
            printf("Actual project name is %s\n", vp->GetName());
            printf("Please type new name [ENTER for cancel]: ");
            char name[256];
            fgets(name, 256, stdin);
            
            if (strlen(name) <= 2) continue;

            CHOMP(name);
            vp->SetName(name);
        }

        if (CMD_IS(line, "setsize")) {
            printf("Actual size is %dx%d\n", vp->GetWidth(), vp->GetHeight());
            printf("Please type new size: [w h]: ");
            int w, h;
            
            char csize[32];
            fgets(csize, 32, stdin);

            if (strlen(csize) <= 2) continue;

            if (sscanf(csize, "%d %d", &w, &h) < 2)
                continue;

            vp->SetWidth(w);
            vp->SetHeight(h);
                        
        }

        if (CMD_IS(line, "setfps")) {
            printf("Actual framerate is %.2f\n", vp->GetFPS());
            printf("Please type new framerate: ");
            float ffps;
            
            char csize[32];
            fgets(csize, 32, stdin);

            if (strlen(csize) <= 2) continue;

            if (sscanf(csize, "%f", &ffps) < 1) {
                int ifps;
                if (sscanf(csize, "%d", &ifps) == 1) {
                   ffps = ifps*1.0f;
                } else {
                    continue;
                }
            }        

            vp->SetFPS(ffps);
                        
        }

        if (CMD_IS(line, "tracks")) {
            TrackCollection* t = vp->GetTracks();
            if (t->GetCount() > 0) {
                
                t->ResetIterator(); 
                Track* tr = t->GetNext();

                int index = 0;
                printf("%zu tracks in this project\n", t->GetCount());
                static const char* typelist[] = {"video", "audio", "text", "unknown"};
                do {
                    printf("\t Track #%2d: %-30s - id %#08x - type %8s\n",
                        index, tr->GetName(), tr->GetID(), 
                        typelist[std::min(tr->GetType(), 3)]);
                    index++;
                } while (tr = t->GetNext());

            } else {
                printf("This project has no tracks\n");
            }
        }

        if (CMD_IS(line, "tracks add")) {
            printf("Track name: ");
            char name[128], type[16];
            fgets(name, 128, stdin);
            
            if (strlen(name) <= 2) continue;
            CHOMP(name);

            printf("Track type: [video|other]: ");
            fgets(type, 16, stdin);
            CHOMP(type);

            Track* t;
            if (CMD_IS(type, "video"))  t = new VideoTrack{};
            else if (CMD_IS(type, "other"))  t = new Track{};
            else    continue;            

            t->SetName(name);

            int i = vp->GetTracks()->AddTrack(t);
            printf("Added track %s with type %s ID %d at pos %d\n",
                t->GetName(), type, t->GetID(), i);         
        }

        if (CMD_IS(line, "tracks remove")) {
            printf("Index: ");
            
            char chindex[8];
            fgets(chindex, 8, stdin);
            
            if (strlen(chindex) < 2) continue;
            
            int index;
            sscanf(chindex, "%d", &index);
        
            Track* t = vp->GetTracks()->GetTrack(index);
            if (!t) {
                printf("Invalid index!");
                continue;
            }
        
            printf("You are about to remove track '%s' (id %#x)\n"
                   "Are you sure? (Y/n): ",
                t->GetName(), t->GetID());

            char c = getc(stdin);
            if (c == 'Y') {
                vp->GetTracks()->DeleteTrack(index);
                printf("Track deleted.\n");
            }
        }
 

    } 
}
