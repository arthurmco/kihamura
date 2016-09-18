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

VideoObject* AnyMedia::GetVideoObject(int index)
{
    if (index > 0) return nullptr;

    char vname[32];
    sprintf(vname, "Video #%p", this);

    size_t num = (size_t)this;
    return new VideoObject{vname, 1280, 720, 30, ((int)num) % 8000,
      VFORMAT_RGB24};
}

int AnyMedia::GetVideoObjectCount()
{
    return 1;
}

AudioObject* AnyMedia::GetAudioObject(int index)
{
    if (index > 0) return nullptr;

    char vname[32];
    sprintf(vname, "Audio #%p", this);

    size_t num = (size_t)this;
    return new AudioObject{vname, 2, 44100, ((int)num) % 8000,
        AUDIO_FORMAT_INT64};
}
int AnyMedia::GetAudioObjectCount()
{
    return 1;
}
