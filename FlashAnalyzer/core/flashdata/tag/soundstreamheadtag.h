#ifndef SOUNDSTREAMHEADTAG_H
#define SOUNDSTREAMHEADTAG_H

#include "tag.h"

class SoundStreamHeadTag : public Tag
{
public:
    SoundStreamHeadTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // SOUNDSTREAMHEADTAG_H
