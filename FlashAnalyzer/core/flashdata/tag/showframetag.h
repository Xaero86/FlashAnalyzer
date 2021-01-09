#ifndef SHOWFRAMETAG_H
#define SHOWFRAMETAG_H

#include "controltag.h"

class ShowFrameTag : public ControlTag
{
public:
    ShowFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // SHOWFRAMETAG_H
