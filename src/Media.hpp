/* Media handling

   Copyright (C) 2016 Arthur M

*/

#include <string>
#include "VideoObject.hpp"
#include "AudioObject.hpp"

#ifndef _MEDIA_HPP
#define _MEDIA_HPP

class Media {
private:
    /* Media name */
    std::string _name;

public:
    Media(const char* name);

    const char* GetName() const;
    void SetName(char*);

    /* Gets the object, but only the minimal amount of video */
    virtual VideoObject* GetVideoObject(int index) = 0;
    virtual AudioObject* GetAudioObject(int index) = 0;

    /*  Get only a small part of the video.
        Returns the object or throws a MediaNotReadyException

        TODO: implement MediaNotReadyException.
    */
    virtual VideoObject* GetVideoObject(VideoObject* obj, long long int start,
        long long int framecount) = 0;
    virtual AudioObject* GetAudioObject(VideoObject* obj, long long int start,
        long long int samplecount) = 0;

    virtual int GetVideoObjectCount() = 0;
    virtual int GetAudioObjectCount() = 0;

};

#endif
