#include "Track.hpp"

Track::Track() 
{
    _id = (unsigned int)(((size_t)this) & 0xffffffff);
}

void Track::SetName(char* n) { _name = n; }
const char* Track::GetName() const {return _name.c_str();}

unsigned int Track::GetID() { return _id; }

int Track::GetType() { return TRACK_UNKNOWN; }
