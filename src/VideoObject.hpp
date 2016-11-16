/*  Represents a video in Kihamura projects

    Copyright (C) 2016 Arthur M
*/

#include <map>
#include <cstdint>

#ifndef _VIDEOOBJECT_HPP
#define _VIDEOOBJECT_HPP

typedef uint8_t VideoRawData;

enum VideoFormat {
    VFORMAT_RGB24,
    VFORMAT_RGBA32,
    VFORMAT_ARGB32,
    VFORMAT_RGB16,
    VFORMAT_RGB8,
};

class VideoObject
{
private:
    /* Object name */
    std::string _name;

    /* Object identificator */
    int _id;

    /* Video size */
    int _width, _height;

    /*  A map between a frame number and a frame data
        You don't need to store every frame, they will be interpolated
        or loaded by demand */
    std::map<int, VideoRawData*> _keyframes;

    /* The video format */
    int _format;

    /* The video framerate */
    float _framerate;

    /*  The video framecount,
        -1 if you want the video to 'never end'.
        It will be able to increase and decrease the length as you wish, like
        some imahes

    */
    int _framecount;

public:
    VideoObject(const char* name, int width, int height, float fps,
        int framecount, int format);

    const char* GetName() const;
    void SetName(const char* n);

    int GetID();

    int GetWidth();
    int GetHeight();

    int GetFormat();
    float GetFramerate();
    int GetFramecount();

    /* Gets a frame on frame position 'f' */
    VideoRawData* GetFrame(int f);

    /* Interpolate a frame on a certain time, in the object space.
        Gets the absolute milissecond */
    VideoRawData* InterpolateFrame(int milissecond);
};

#endif
