#include "VideoTrack.hpp"


VideoTrack::VideoTrack() : Track()
{}

int VideoTrack::GetType() 
{
    return TRACK_VIDEO;
}

void VideoTrack::GetPosition(double& x, double& y)
{
    x = _xPos;     y = _yPos;
}

void VideoTrack::GetPosition(double& x, double& y, double& z)
{
    x = _xPos;     y = _yPos;      z = _zPos;
}

void VideoTrack::SetPosition(double x, double y)
{
    _xPos = x;     _yPos = y;
}
void VideoTrack::SetPosition(double x, double y, double z)
{
    _xPos = x;     _yPos = y;      _zPos = z;
}
