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


    virtual VideoObject* GetVideoObject(int index) = 0;
    virtual AudioObject* GetAudioObject(int index) = 0;


    virtual int GetVideoObjectCount() = 0;
    virtual int GetAudioObjectCount() = 0;

};

#endif
