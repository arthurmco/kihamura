#include "FileMediaOpener.hpp"

FileMediaOpener* FileMediaOpener::__instance = nullptr;


/* Register a single media type for one or more extensions */
void FileMediaOpener::RegisterMedia(FileMedia* media, 
    int extcount, const char** exts)
{
    for (int i = 0; i < extcount; i++) {
        std::string e{exts[i]};
        if (_open_binders.find(e) == _open_binders.end()) {
            _open_binders[e] = media;
        }
    }
}

/* Open the file using the automatic detection */
FileMedia* FileMediaOpener::Open(const char* path)
{
    std::string spath{path};

    int dotindex = spath.find_last_of('.');
    std::string ext;

    if (dotindex == std::string::npos) {
        ext = "";
    } else {
        ext = spath.substr(dotindex+1);
    }

    this->Open(path, ext.c_str());
        
}

/* Open the file using a different extension */
FileMedia* FileMediaOpener::Open(const char* path, const char* ext)
{
    auto f = _open_binders.find(std::string{ext});
    if (f == _open_binders.end())   return nullptr;

    FileMedia* fm = f->second->Clone()->Replace(path);

    if (fm)
        return fm;
    else 
        return nullptr;
}

