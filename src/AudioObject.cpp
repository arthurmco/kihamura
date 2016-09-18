#include "AudioObject.hpp"

AudioObject::AudioObject(const char* name, int channels, int bitrate,
    int sample_count, int format)
{
    _name = std::string{name};
    _channel_count = channels;
    _bitrate = bitrate;
    _sample_count = sample_count;
    _format = format;

    _id = ((int) (((size_t)this) & 0xffffffff));
}

int AudioObject::GetID() const
{
    return _id;
}

const char* AudioObject::GetName() const
{
    return _name.c_str();
}

void AudioObject::SetName(char* c)
{
    _name = std::string{c};
}

int AudioObject::GetChannelCount() const
{
    return _channel_count;
}

double AudioObject::GetVolume() const
{
    return _volume_mult;
}

void AudioObject::SetVolume(double v)
{
    _volume_mult = v;
}

int AudioObject::GetBitrate() const
{
    return _bitrate;
}

long int AudioObject::GetSampleCount() const
{
    return _sample_count;
}

int AudioObject::GetFormat() const
{
    return _format;
}

AudioRawData* AudioObject::InterpolateSample(long int sample_index)
{
    //unsafe, but i need to implement this anyway.
    AudioRawData a = 1;
    return &a;
}
