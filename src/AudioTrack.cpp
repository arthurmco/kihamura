#include "AudioTrack.hpp"

AudioTrack::AudioTrack() : Track()
{}

int AudioTrack::GetType()
{
    return TRACK_AUDIO;
}

double AudioTrack::GetVolume() const
{
    return _volume;
}
void AudioTrack::SetVolume(double v)
{
    _volume = v;
}

/* Add an audio clip in this track, at frame position 'frame' */
void AudioTrack::AddAudioClip(int frame, AudioClip* clip)
{
    if (_clips.find(frame) == _clips.end())
        _clips[frame] = clip;
}

/* Get the audio clip at frame position 'frame' */
AudioClip* AudioTrack::GetAudioClip(int frame)
{
    if (_clips.find(frame) == _clips.end())
        return nullptr;
    else
        return _clips[frame];
}


void AudioTrack::ResetIterator()
{
    _it = _clips.begin();
}

/*  Returns the clip pointer, and stores its frame at 'frame'

    Returns nullptr and sets frame to -1 if no more frames.
 */
Clip* AudioTrack::GetNextObject(int& frame)
{
    if (_it == _clips.end()) {
        frame = -1;
        return nullptr;
    } else {
        frame = _it->first;
    }

    Clip* o = (Clip*)_it->second;
    _it++;
    return o;
}
