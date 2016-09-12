#include "VideoProject.hpp"

VideoProject::VideoProject(char* name, 
    int width, int height, float fps, int bitrate)
{
    _name = name;
    _defWidth = width;
    _defHeight = height;
    _defFramerate = fps;
    _defAudioBitrate = bitrate;

    _trackcol = new TrackCollection;
    _mediacol = new MediaCollection;
}

VideoProject::~VideoProject()
{
    delete _trackcol;
    delete _mediacol;
}

/* Open a project from a file */
void VideoProject::Open(const char* filename)
{
    (void)filename;
}

/* Save the project */
void VideoProject::Save()
{
    this->Save(_filename);
}

void VideoProject::Save(const char* filename)
{

}
    
char* VideoProject::GetName() { return _name; }
void VideoProject::SetName(char* name) { _name = name; }

int VideoProject::GetWidth() { return _defWidth; }
int VideoProject::GetHeight() { return _defHeight; }
void VideoProject::SetWidth(int w) { _defWidth = w; }
void VideoProject::SetHeight(int h) {_defHeight = h; }

float VideoProject::GetFPS() { return _defFramerate; }
void VideoProject::SetFPS(float fps) { _defFramerate = fps; }

int VideoProject::GetBitrate(){ return _defAudioBitrate; }
void VideoProject::SetBitrate(int brate) { _defAudioBitrate = brate; }

char* VideoProject::GetFileName() { return _filename; }

TrackCollection* VideoProject::GetTracks() { return _trackcol; }
MediaCollection* VideoProject::GetMedia() { return _mediacol; }
