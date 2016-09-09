#include "VideoProject.hpp"

VideoProject::VideoProject(char* name, 
    int width, int height, float fps, int bitrate)
{
    _name = name;
    _defaultWidth = width;
    _defaultHeight = height;
    _defaultFramerate = fps;
    _defaultAudioBitrate = bitrate;
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

int VideoProject::GetWidth() { return _defaultWidth; }
int VideoProject::GetHeight() { return _defaultHeight; }
void VideoProject::SetWidth(int w) { _defaultWidth = w; }
void VideoProject::SetHeight(int h) {_defaultHeight = h; }

float VideoProject::GetFPS() { return _defaultFramerate; }
void VideoProject::SetFPS(float fps) { _defaultFramerate = fps; }

int VideoProject::GetBitrate(){ return _defaultAudioBitrate; }
void VideoProject::SetBitrate(int brate) { _defaultAudioBitrate = brate; }

char* VideoProject::GetFileName() { return _filename; }
