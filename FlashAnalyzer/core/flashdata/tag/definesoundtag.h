#ifndef DEFINESOUNDTAG_H
#define DEFINESOUNDTAG_H

#include "tag.h"

class DefineSoundTag : public Tag
{
public:
    DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINESOUNDTAG_H
