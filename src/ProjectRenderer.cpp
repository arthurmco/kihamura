#include "ProjectRenderer.hpp"

ProjectRenderer::ProjectRenderer(VideoProject* p) : _proj{p}
{}
/*  Renders an array containing pointers to the frame/sample data

    The render can optimize this to render frames second by second,
    or keyframe to keyframe.
 */
VideoRawData** ProjectRenderer::RenderFrames(long long int framestart, int count)
{
    TrackCollection* col = _proj->GetTracks();

    Track* t;
    col->ResetIterator();
    VideoClip* c;

    /*  Get the video at same position for each track.
        Blend videos only if their track/media opacity is below 100 */

    while (t = col->GetNext()) {
        VideoTrack* vt = dynamic_cast<VideoTrack*>(t);
        if (!vt) continue; //It wasn't a video track originally

        c = vt->GetVideoClip(framestart);
        


    }

}
AudioRawData** ProjectRenderer::RenderSample(long long int samplestart, int count)
{

}
