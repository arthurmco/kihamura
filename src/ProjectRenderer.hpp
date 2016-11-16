/*  Project rendering class

    Copyright (C) 2016 Arthur M
*/

#include "VideoProject.hpp"
#include "Media.hpp"

#ifndef _PROJECT_RENDERER_HPP
#define _PROJECT_RENDERER_HPP

class ProjectRenderer
{
private:
    VideoProject* _proj;

public:
    ProjectRenderer(VideoProject*);
    /*  Renders an array containing pointers to the frame/sample data

        The render can optimize this to render frames second by second,
        or keyframe to keyframe.
     */
    VideoRawData** RenderFrames(long long int framestart, int count);
    AudioRawData** RenderSample(long long int samplestart, int count);
}

#endif
