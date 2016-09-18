#include "AudioClip.hpp"

AudioClip::AudioClip(AudioObject* obj, int frameStart, int frameLength) :
    Clip(frameStart, frameLength)
{
    _obj = obj;
}

AudioObject* AudioClip::GetObject()
{
    return _obj;
}

int old_mute_bitmask;
void AudioClip::MuteChannel(int ch)
{
    _enabled_channels |= (1 << --ch);
}
void AudioClip::UnmuteChannel(int ch)
{
    _enabled_channels ^= (1 << --ch);
}

/* Save the mute bitmask somewhere and set it to 0xffffffff */
void AudioClip::MuteAll()
{
    old_mute_bitmask = _enabled_channels;
    _enabled_channels = -1;
}

/* Restore the old mute bitmask */
void AudioClip::UnmuteAll()
{
    _enabled_channels = old_mute_bitmask;
}
