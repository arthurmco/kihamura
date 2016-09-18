/*  Base class for clips

    Copyright (C) 2016 Arthur M
*/

#ifndef _CLIP_HPP
#define _CLIP_HPP

class Clip {
protected:

    /* Where does this clip starts and ends from that object */
    int _frameStart, _frameLength;

public:
    Clip(int frameStart, int frameLength);

    int GetObjectStartPoint() const;
    int GetObjectLength() const;

    void SetObjectStartPoint(int);
    void SetObjectLength(int);

    virtual void* GetObject() = 0;
};


#endif /* end of include guard: _CLIP_HPP */
