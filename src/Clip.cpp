#include "Clip.hpp"

Clip::Clip(int frameStart, int frameLength)
{
    _frameStart = frameStart;
    _frameLength = frameLength;
}

int Clip::GetObjectStartPoint() const
{
    return _frameStart;
}
int Clip::GetObjectLength() const
{
    return _frameLength;
}

void Clip::SetObjectStartPoint(int s)
{
    _frameStart = s;
}

void Clip::SetObjectLength(int l)
{
    _frameLength = l;
}
