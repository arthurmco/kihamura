/*  Video project support

    Copyright (C) 2016 Arthur M

*/

#ifndef _VIDEOPROJECT_HPP
#define _VIDEOPROJECT_HPP

class VideoProject
{
private:
    /* The project name */
    char* _name;

    /* The project default size */    
    int _defaultWidth, _defaultHeight;

    /* Project default video framerate and audio bitrate in kbps */
    float _defaultFramerate;
    int _defaultAudioBitrate;

    /* File name and descriptor */
    char* _filename;
    int _fd;

public:
    VideoProject(char* name, int width, int height, float fps, int bitrate);

    /* Open a project from a file */
    void Open(const char* filename);

    /* Save the project */
    void Save();
    void Save(const char* filename);
    
    char* GetName();
    void SetName(char* name);

    int GetWidth();
    int GetHeight();
    void SetWidth(int);
    void SetHeight(int);

    float GetFPS();
    void SetFPS(float);

    int GetBitrate();
    void SetBitrate(int);

    char* GetFileName();
};


#endif
