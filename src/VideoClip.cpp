#include "VideoClip.hpp"

VideoClip::VideoClip(VideoObject* obj, int frameStart, int frameLength)
    : Clip(frameStart, frameLength)
{
    _obj = obj;
}

int VideoClip::GetWidth() const
{
    return _width;
}

void VideoClip::SetWidth(int w)
{
    _width = w;
}

int VideoClip::GetHeight() const
{
    return _height;
}

void VideoClip::SetHeight(int h)
{
    _height = h;
}

void VideoClip::GetPositions(double& x, double& y) const
{
    x = _x;
    y = _y;
}

void VideoClip::GetPositions(double& x, double& y, double& z) const
{
    x = _x;
    y = _y;
    z = _z;
}

void VideoClip::SetPositions(double x, double y)
{
    _x = x;
    _y = y;
}

void VideoClip::SetPositions(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

VideoObject* VideoClip::GetObject()
{
    return _obj;
}

/*  Returns the clip data at a certain time, in clip space
    In this case, returns the video frame data.
*/
VideoRawData* VideoClip::GetObjectDataAtTime(int milissecond)
{
    float fps = _obj->GetFramerate();
    int frame = (milissecond * fps) / 1000;

    if (frame > frameLength) return nullptr;

    return _obj->GetFrame(_frameStart + frame);
}
