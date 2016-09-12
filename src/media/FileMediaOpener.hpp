/*  File media opener class

    Copyright (C) 2016 Arthur M
*/

#include <string>
#include <map>

#include "FileMedia.hpp"

#ifndef _FILE_MEDIA_OPENER
#define _FILE_MEDIA_OPENER

class FileMediaOpener 
{
private:
    std::map<std::string, FileMedia*> _open_binders;
    static FileMediaOpener* __instance;

public:
    /* Register a single media type for one or more extensions */
    void RegisterMedia(FileMedia* media, int extcount, const char** exts);

    /* Open the file using the automatic detection */
    FileMedia* Open(const char* path);

    /* Open the file using a different extension parser

       The file doesn't need to be using the new extension
    */
    FileMedia* Open(const char* path, const char* ext);

    static FileMediaOpener* GetInstance()
    {
        if (!__instance)    __instance = new FileMediaOpener{};
        return __instance;
    }
    
};

#endif
