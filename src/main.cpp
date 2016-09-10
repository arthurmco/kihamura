/*
    Main file

    Copyright (C) 2016 Arthur M

*/

#include <cstdio>
#include <cstring>

#include "VideoProject.hpp"

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

    } 
}
