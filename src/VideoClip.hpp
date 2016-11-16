/*  Video clip definitions

    Copyright (C) 2016 Arthur M
*/

#include "VideoObject.hpp"
#include "Clip.hpp"

#ifndef _VIDEO_CLIP_HPP
#define _VIDEO_CLIP_HPP

/*
    A video clip is a video representation in the tracks.
    It can be parts of a video file, or the video file itself

*/

class VideoClip : public Clip {
private:
    /* Clip width and height */
    int _width, _height;

    /* Clip positions */
    double _x = 0.0, _y = 0.0, _z = 1.0;

    /* Object that this clip is derived from */
    VideoObject* _obj;

    /* Effects */
    // std::list<VideoEffect*> _effects;

    /* Starting and ending transitions */
    // VideoTransition* _transitionStart, _transitionEnd;

public:
    VideoClip(VideoObject* obj, int frameStart, int frameLength);

    int GetWidth() const;
    void SetWidth(int);

    int GetHeight() const;
    void SetHeight(int);

    void GetPositions(double& x, double& y) const;
    void GetPositions(double& x, double& y, double& z) const;
    void SetPositions(double x, double y);
    void SetPositions(double x, double y, double z);

    virtual VideoObject* GetObject() override;

    /*  Returns the clip data at a certain time, in clip space
        In this case, returns the video frame data.
    */
    virtual void* GetObjectDataAtTime(int milissecond) override;
};

#endif
