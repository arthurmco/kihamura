/*  Any media that comes from a file

    Copyright (C) 2016 Arthur M
*/

#include "../Media.hpp"
#include <string>

#include <unistd.h> //for close()

#ifndef _FILE_MEDIA_HPP
#define _FILE_MEDIA_HPP

class FileMedia : public Media {
protected:
    /* The path */
    std::string _path;

    /* The file descriptor */
    int _fd;

public:
    FileMedia(const char* path);

    /* Opens (or reopens) the file */
    virtual bool Open() = 0;

    /* Replaces the file */
    FileMedia* Replace(const char* path);

    /* Clone a file in memory */
    virtual FileMedia* Clone() = 0;

    /* Closes the file */
    bool Close();
    
    const char* GetPath() const;
};


#endif
