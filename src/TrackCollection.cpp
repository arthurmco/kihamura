#include "TrackCollection.hpp"


/* Adds a track, return its index into the collection */
int TrackCollection::AddTrack(Track* t)
{
    int i = _tracks.size();
    _tracks.push_back(t);
    return i;
}

/* Inserts a track on a specified index */
void TrackCollection::Insert(Track* t, int index)
{
    if (index > _tracks.size()) index = _tracks.size();

    auto it = _tracks.begin();
    std::advance(it, index);
    _tracks.insert(it, t);
}

/* Gets a track */
Track* TrackCollection::GetTrack(int index) const
{
    auto pos = _tracks.begin();
    if (index > _tracks.size()) return nullptr;

    std::advance(pos, index);
    return *pos;
}

Track* TrackCollection::GetTrack(const char* name) const
{
    for (auto it : _tracks) {
        if (!strcmp(name, it->GetName())) {
            return it;
        }
    }
    return nullptr;
}    

/* Get the track index */
int TrackCollection::GetTrackIndex(Track* t) const
{
    unsigned int id = t->GetID();
    int index = 0;
    for (auto it : _tracks) {
        if (it->GetID() == id) {
            return index;
        }
    }

    return -1;
}

/* Delete a track by its index */
void TrackCollection::DeleteTrack(int index)
{
    if (index > _tracks.size()) return;

    auto it = _tracks.begin();
    std::advance(it, index);
    
    _tracks.erase(it);
}

size_t TrackCollection::GetCount() { return _tracks.size(); }

void TrackCollection::ResetIterator()
{
    _iterator = _tracks.begin();
}

Track* TrackCollection::GetNext() 
{
    if (_iterator == _tracks.end())
        return nullptr;

    Track* t = *_iterator;
    _iterator++;
    return t;
}
