/*  Definitions of an audio track

    Copyright (C) 2016 Arthur M
*/

#include <map>
#include "Track.hpp"
#include "AudioClip.hpp"

#ifndef _AUDIO_TRACK_HPP
#define _AUDIO_TRACK_HPP

class AudioTrack : public Track
{
private:
    /* General volume configs for the entire track */
    double _volume = 1.0;

    /* Video clips in this track */
    std::map<int /*frame*/, AudioClip*> _clips;

    std::map<int /*frame*/, AudioClip*>::iterator _it;

public:
    AudioTrack();

    int GetType();

    double GetVolume() const;
    void SetVolume(double);

    /* Add an audio clip in this track, at frame position 'frame' */
    void AddAudioClip(int frame, AudioClip* clip);

    /* Get the audio clip at frame position 'frame' */
    AudioClip* GetAudioClip(int frame);


    virtual void ResetIterator();

    /*  Returns the clip pointer, and stores its frame at 'frame'

        Returns nullptr and sets frame to -1 if no more frames.
     */
    virtual Clip* GetNextObject(int& frame);
};



#endif /* end of include guard: _AUDIO_TRACK_HPP */
