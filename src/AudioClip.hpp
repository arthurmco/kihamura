/*  Audio clip definitions

    Copyright (C) 2016 Arthur M
*/

#include "AudioObject.hpp"
#include "Clip.hpp"

#ifndef _AUDIO_CLIP_HPP
#define _AUDIO_CLIP_HPP

class AudioClip : public Clip
{
private:
    /*  An bitmask of enabled channels.
        (only 32 channels supported, but no problem) */
    int _enabled_channels = -1; // enable all channels by default.

    AudioObject* _obj;

    /*  In this class, we choose, as placement method, the FRAME OFFSET and
        FRAME COUNT of the audio clip, directly inherited from Clip class
        This might not be the right thing to do, but is more portable
        (you can switch and replace files of different bitrates) and
        the conversion isn't much hard to do */

    /* Effects */
    // std::list<AudioEffect*> _effects;

    /* Starting and ending transitions */
    // AudioTransition* _transitionStart, _transitionEnd;

public:
    AudioClip(AudioObject* obj, int frameStart, int frameLength);

    virtual AudioObject* GetObject() override;

    void MuteChannel(int);
    void UnmuteChannel(int);

    /* Save the mute bitmask somewhere and set it to 0xffffffff */
    void MuteAll();

    /* Restore the old mute bitmask */
    void UnmuteAll();
};


#endif /* end of include guard: _AUDIO_CLIP_HPP */
