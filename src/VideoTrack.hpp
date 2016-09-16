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
    std::map<int /*frame*/, VideoClip*> _clips;
   
    std::map<int /*frame*/, VideoClip*>::iterator _it;

public:
    VideoTrack();

    int GetType();

    void GetPosition(double& x, double& y);
    void GetPosition(double& x, double& y, double& z);

    void SetPosition(double x, double y);
    void SetPosition(double x, double y, double z);

    /* Add a video clip in this track, at frame position 'frame' */
    void AddVideoClip(int frame, VideoClip* clip);

    /* Get the video clip at frame position 'frame' */
    VideoClip* GetVideoClip(int frame);
    
    virtual void ResetIterator();

    /*  Returns the first frame of the clip and 'object' as a pointer to the
        clip pointer

        If the iterator is over, 'object' pointed value is nullptr and the
        code returns 1
     */
    virtual int GetNextObject(void** object);
};

#endif
