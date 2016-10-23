/*  Video project support

    Copyright (C) 2016 Arthur M

*/

#include <string>
#include "TrackCollection.hpp"
#include "MediaCollection.hpp"

#ifndef _VIDEOPROJECT_HPP
#define _VIDEOPROJECT_HPP

class VideoProject
{
private:
    /* The project name */
    std::string _name;

    /* The project default size */
    int _defWidth, _defHeight;

    /* Project default video framerate and audio bitrate in kbps */
    float _defFramerate;
    int _defAudioBitrate;

    /* File name and descriptor */
    char* _filename;
    int _fd;

    /* Track collection */
    TrackCollection* _trackcol;

    /* Project media collection */
    MediaCollection* _mediacol;

public:
    VideoProject(char* name, int width, int height, float fps, int bitrate);
    ~VideoProject();

    /* Open a project from a file */
    void Open(const char* filename);

    /* Save the project */
    void Save();
    void Save(const char* filename);

    const char* GetName() const;
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

    TrackCollection* GetTracks();
    MediaCollection* GetMedia();
};


#endif
