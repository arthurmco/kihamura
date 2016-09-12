#include "FileMedia.hpp"

FileMedia::FileMedia(const char* path)
    : Media(path)
{
    _path = std::string{path};
}

FileMedia* FileMedia::Replace(const char* path) 
{
    _path = std::string{path};
    this->SetName(const_cast<char*>(path));
    if (this->Open())
        return this;
    else
        return nullptr;
}

bool FileMedia::Close() 
{
    close(_fd);
}

const char* FileMedia::GetPath() const
{
    _path.c_str();
}
