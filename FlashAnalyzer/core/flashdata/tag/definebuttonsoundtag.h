#ifndef DEFINEBUTTONSOUNDTAG_H
#define DEFINEBUTTONSOUNDTAG_H

#include "tag.h"

class DefineButtonSoundTag : public Tag
{
public:
    DefineButtonSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEBUTTONSOUNDTAG_H
