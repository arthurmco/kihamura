#include "Track.hpp"

Track::Track() 
{
    _id = (unsigned int)(((size_t)this) & 0xffffffff);
}

void Track::SetName(char* n) { _name = n; }
char* Track::GetName() {return _name;}

unsigned int Track::GetID() { return _id; }
