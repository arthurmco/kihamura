#include "MediaCollection.hpp"

MediaCollection* MediaCollection::__instance = nullptr;

Media* MediaCollection::GetMedia(const char* name)
{
    for (auto media : _medialist) {
        if (!strcmp(media->GetName(), name)) {
            return media;
        }
    }
    return nullptr;
}

Media* MediaCollection::GetMedia(int index)
{

    if (index >= _medialist.size()) return nullptr;

    auto it = _medialist.begin();
    std::advance(it, index);

    return *it;
}

bool MediaCollection::AddMedia(Media* m)
{
    if (!this->GetMedia(m->GetName())) {
        _medialist.push_back(m);

        if (this != MediaCollection::GetInstance())
            return MediaCollection::GetInstance()->AddMedia(m);
    }

    /* There's some media with the same name of ours */
    return false;
}

bool MediaCollection::RemoveMedia(Media* m)
{
    const char* n = m->GetName();
    for (auto it = _medialist.begin(); it != _medialist.end(); ++it)
    {
        if (!strcmp((*it)->GetName(), n)) {
            _medialist.erase(it);
            return true;
        }
    }

    return false;
}

/* Copy media between collections */
bool MediaCollection::CopyMedia(MediaCollection* col, Media* m)
{
    if (!this->GetMedia(m->GetName())) return false;
   
    if (!col->GetMedia(m->GetName())) {
        col->_medialist.push_back(m);
        return true;
    } else {
        return false;
    }
}

/* Move media between collections */
bool MediaCollection::MoveMedia(MediaCollection* col, Media* m)
{
    /* Note that you can't move from the singleton */
    if (MediaCollection::GetInstance() == this) return false;
    if (!this->GetMedia(m->GetName())) return false;

    if (!this->CopyMedia(col, m)) return false;
    this->RemoveMedia(m);
    return true;
}


size_t MediaCollection::GetCount() 
{
    return _medialist.size();
}

void MediaCollection::ResetIterator()
{
    _mediait = _medialist.begin();
}

Media* MediaCollection::GetNext()
{
    if (_mediait == _medialist.end()) return nullptr;

    Media* m = (*_mediait);
    _mediait++;

    return m;
}
