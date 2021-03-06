#include "VideoObject.hpp"

VideoObject::VideoObject(const char* name, int width, int height, float fps,
   int framecount, int format)
{
    _name = std::string{name};

    _id = ((int) (((size_t)this) & 0xffffffff));
    _width = width;
    _height = height;

    _format = format;
    _framerate = fps;
    _framecount = framecount;
}

const char* VideoObject::GetName() const
{
    return _name.c_str();
}

void VideoObject::SetName(const char* n)
{
    _name = std::string{n};
}

int VideoObject::GetID()
{
    return _id;
}

int VideoObject::GetWidth()
{
    return _width;
}

int VideoObject::GetHeight()
{
    return _height;
}

int VideoObject::GetFormat()
{
    return _format;
}

float VideoObject::GetFramerate()
{
    return _framerate;
}

int VideoObject::GetFramecount()
{
    return _framecount;
}

/* Gets a frame on frame position 'f' */
VideoRawData* VideoObject::GetFrame(int f)
{
    return nullptr;
}

/* Interpolate a frame on a certain time, in the object space.
    Gets the absolute milissecond */
VideoRawData* InterpolateFrame(int milissecond)
{
    float frame = (milissecond * _framerate) / 1000;

    return nullptr;
}
