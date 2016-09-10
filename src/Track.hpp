/*  Basic default class for tracks on Kihamura

    Copyright (C) 2016 Arthur M 
*/

#include <cstdlib>

#ifndef _TRACK_HPP
#define _TRACK_HPP

class Track 
{
private:
    char* _name;
    unsigned int _id;

public:
    Track();

    void SetName(char*);
    char* GetName();    

    unsigned int GetID();
};


#endif
