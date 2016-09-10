/*  Definitions for video tracks

    Copyright (C) 2016 Arthur M
*/

#include "Track.hpp"

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
public:
    VideoTrack();

    int GetType();

    void GetPosition(double& x, double& y);
    void GetPosition(double& x, double& y, double& z);

    void SetPosition(double x, double y);
    void SetPosition(double x, double y, double z);

};

#endif
