/*  Represents a collection of tracks

    Copyright (C) 2016 Arthur M
*/

#include <list>
#include <iterator> //std::advance()

#include <cstring>

#include "Track.hpp"

#ifndef _TRACK_COLLECTION_HPP
#define _TRACK_COLLECTION_HPP


class TrackCollection {
private:
    std::list<Track*> _tracks;

    std::list<Track*>::iterator _iterator;

public:
    /* Adds a track, return its index into the collection */
    int AddTrack(Track*);

    /* Inserts a track on a specified index */
    void Insert(Track* t, int index);

    /* Gets a track */
    Track* GetTrack(int index) const;
    Track* GetTrack(const char* name) const;
    
    /* Get the track index */
    int GetTrackIndex(Track*) const;

    /* Delete a track by its index */
    void DeleteTrack(int index);

    /* Get track count */
    size_t GetCount();

    /* Controls the track iterator */
    void ResetIterator();
    Track* GetNext();
};

#endif
