/*  Media collection management class

    Copyright (C) 2016 Arthur M
*/

#include <list>
#include <cstring>

#include "Media.hpp"

#ifndef _MEDIA_COLLECTION_HPP
#define _MEDIA_COLLECTION_HPP

/*  This is the media collection class, that can be used as a instanced or
    a singleton class
    The singleton will serve as a media repository across all open projects,
    so we can save some memory. The instanced version can be used as a 
    generic container
*/

class MediaCollection
{
private:
    std::list<Media*> _medialist;
    std::list<Media*>::iterator _mediait;    

    static MediaCollection* __instance;

public:
    Media* GetMedia(const char* name); 
    Media* GetMedia(int index); 

    bool AddMedia(Media* m);
    bool RemoveMedia(Media* m);
 
    /* Copy media 'm' to collection 'col'.
       Returns true on success, false on failure */
    bool CopyMedia(MediaCollection* col, Media* m);

    /* Move media 'm' to collection 'col'. */
    bool MoveMedia(MediaCollection* col, Media* m);
 
    size_t GetCount(); 

    /* Iterator */
    void ResetIterator();
    Media* GetNext();    

    
    static MediaCollection* GetInstance()
    {
        if (!__instance) __instance = new MediaCollection{};
        return __instance;
    }
};

#endif
