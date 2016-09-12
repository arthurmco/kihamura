/* Media handling

   Copyright (C) 2016 Arthur M

*/

#include <string>

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

/*
    VideoObject* GetVideoObject(int index);
    AudioObject* GetAudioObject(int index);
*/

    int GetVideoObjectCount();
    int GetAudioObjectCount();

};

#endif
