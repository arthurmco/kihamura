/*  Represents a video in Kihamura projects

    Copyright (C) 2016 Arthur M
*/

#include <map>
#include <cstdint>

#ifndef _VIDEOOBJECT_HPP
#define _VIDEOOBJECT_HPP

typedef VideoRawData uint8_t;

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
    char* _name;

    /* Object identificator */
    int _id;

    /* Video size */
    int _width, _height;
    
    /*  A map between a frame number and a frame data
        You don't need to store every frame, they will be interpolated
        or loaded by demand */      
    std::map<int, VideoRawData*> _keyframes;

    /* The video format */
    int format;

    /* The video framerate */
    float framerate;

public 

}.

#endif
