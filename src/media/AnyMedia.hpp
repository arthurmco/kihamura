/*  Temporary opener that can open any type of media
    
    Copyright (C) 2016 Arthur M
*/

#include "FileMedia.hpp"
#include "FileMediaOpener.hpp"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef _ANY_MEDIA_HPP
#define _ANY_MEDIA_HPP

class AnyMedia : public FileMedia {


public:
    AnyMedia(const char* path);

    virtual bool Open() override;
    virtual FileMedia* Clone() override;

    virtual VideoObject* GetVideoObject(int index) override;
    virtual int GetVideoObjectCount() override;
};

#endif
