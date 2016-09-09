/*
    Main file

    Copyright (C) 2016 Arthur M

*/

#include <cstdio>

#include "VideoProject.hpp"

int main(int argc, char **argv)
{
    VideoProject* vp = new VideoProject{"Test", 720, 480, 29.97f, 192000};
    printf("Project %s created\n", vp->GetName());
    printf("Size: %dx%d, %.2f fps, %.3f kbps of bitrate\n", 
        vp->GetWidth(), vp->GetHeight(), vp->GetFPS(), 
        vp->GetBitrate() / 1000.0f);
    
 


}
