/*  Definitions for video tracks

    Copyright (C) 2016 Arthur M
*/

#include "Track.hpp"
#include "VideoClip.hpp"
#include <map>

#ifndef _VIDEO_TRACK_HPP
#define _VIDEO_TRACK_HPP

class VideoTrack : public Track
{
private:
    /* Track position relative to screen, in normalized coordinates
        ( 0.0 is position 0, 1.0 is the width/height of the screen)
    */
    double _xPos = 0.0, _yPos = 0.0, _zPos = 1.0;

    /* Track opacity, (0.0 = transparent, 1.0 = opaque) */
    double _opacity;

    /* Video clips in this track */
    std::map<int /*ms*/, VideoClip*> _clips;

    std::map<int /*ms*/, VideoClip*>::iterator _it;

public:
    VideoTrack();

    int GetType();

    void GetPosition(double& x, double& y);
    void GetPosition(double& x, double& y, double& z);

    void SetPosition(double x, double y);
    void SetPosition(double x, double y, double z);

    /* Add a video clip in this track, at milissecond 'ms' position */
    void AddVideoClip(int ms, VideoClip* clip);

    /* Get the video clip at milissecond time 'ms'*/
    VideoClip* GetVideoClip(int ms);

    /* Get the video frame that can be seen on this track at milisecond time
        'ms' */
    VideoObject* GetVideoObject(int ms);

    virtual void ResetIterator();

    /*  Returns the clip pointer, and stores its frame at 'frame'

        Returns nullptr and sets frame to -1 if no more frames.
     */
    virtual Clip* GetNextObject(int& frame);
};

#endif
