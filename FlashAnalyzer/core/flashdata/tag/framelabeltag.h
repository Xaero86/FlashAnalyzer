#ifndef FRAMELABELTAG_H
#define FRAMELABELTAG_H

#include "tag.h"

class FrameLabelTag : public Tag
{
public:
    FrameLabelTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // FRAMELABELTAG_H
