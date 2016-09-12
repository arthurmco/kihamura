#include "AnyMedia.hpp"

AnyMedia::AnyMedia(const char* path) : 
    FileMedia(path) 
{
    static bool registered=false;

    if (!registered) {
        static const char* ext[] = {"*"};
        FileMediaOpener::GetInstance()->RegisterMedia(this, 1, ext);
        registered = true;        
    }
}

bool AnyMedia::Open()
{
    _fd = open(_path.c_str(), O_RDONLY);
    return (_fd > 0);
}

FileMedia* AnyMedia::Clone()
{
    return new AnyMedia(*this);
}
