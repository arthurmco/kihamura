/*  Represents an audio in Kihamura projects

    Copyright (C) 2016 Arthur M
*/

#include <map>
#include <string>

#ifndef _AUDIO_OBJECT_HPP
#define _AUDIO_OBJECT_HPP

/* Maximum precision for audio raw data */
typedef uint64_t AudioRawData;

/* Audio formats */
enum AudioFormat {
    AUDIO_FORMAT_INT32,
    AUDIO_FORMAT_FLOAT32,
    AUDIO_FORMAT_INT64,
    AUDIO_FORMAT_FLOAT64,
};


class AudioObject
{
private:
    /* Audio object name */
    std::string _name;

    /* Audio object identificator */
    int _id;

    /* Audio channel count */
    int _channel_count = 1;

    /* Volume multiplier (1.0 for same level as original )*/
    double _volume_mult = 1.0;

    /* Audio bitrate, in bytes per second */
    int _bitrate;

    /* Audio length, in samples */
    long int _sample_count;

    int _format;

    /*  An array of samples value per bit index, in bitrate
        (e.g. the index value 44100, at 44100bps, means that that sample is
        at the audio time of 1 second)

        Each index of the AudioRawData pointed value is the sample value of
        each channel
    */
    std::map<long int, AudioRawData*> _samples;

public:
    AudioObject(const char* name, int channels, int bitrate,
        int sample_count, int format);

    int GetID() const;

    const char* GetName() const;
    void SetName(char* c);

    int GetChannelCount() const;

    double GetVolume() const;
    void SetVolume(double v);

    long int GetSampleCount() const;

    int GetFormat() const;

    int GetBitrate() const;

    AudioRawData* InterpolateSample(long int sample_index);

};


#endif
