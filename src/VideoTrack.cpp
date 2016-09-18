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

void VideoTrack::AddVideoClip(int frame, VideoClip* clip)
{
    if (_clips.find(frame) == _clips.end())
        _clips[frame] = clip;
}

VideoClip* VideoTrack::GetVideoClip(int frame)
{
    if (_clips.find(frame) == _clips.end())
        return nullptr;
    else
        return _clips[frame];
}

void VideoTrack::ResetIterator()
{
    _it = _clips.begin();
}

/*  Returns the clip pointer, and stores its frame at 'frame'

    Returns nullptr and sets frame to -1 if no more frames.
 */
Clip* VideoTrack::GetNextObject(int& frame)
{
    if (_it == _clips.end()) {
        frame = -1;
        return nullptr;
    } else {
        frame = _it->first;
    }

    Clip* o = (Clip*)_it->second;
    _it++;
    return o;
}
