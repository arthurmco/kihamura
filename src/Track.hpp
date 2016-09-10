/*  Basic default class for tracks on Kihamura

    Copyright (C) 2016 Arthur M 
*/

#include <cstdlib>
#include <string>

#ifndef _TRACK_HPP
#define _TRACK_HPP


/*  Common track type definitions
    Every inherited track should resolve to one of those */
enum TrackType {
    TRACK_VIDEO,    /* Video tracks */
    TRACK_AUDIO,    /* Audio tracks */
    TRACK_TEXT,     /* Text tracks. Generally subtitles or closed captioned text */
    TRACK_UNKNOWN = 0xff
};

class Track 
{
private:
    unsigned int _id;

protected:
    std::string _name;

public:
    Track();

    void SetName(char*);
    const char* GetName() const;    

    unsigned int GetID();
    virtual int GetType();
};


#endif
