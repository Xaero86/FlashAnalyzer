#ifndef DEFINEFONTNAMETAG_H
#define DEFINEFONTNAMETAG_H

#include "tag.h"

class DefineFontNameTag : public Tag
{
public:
    DefineFontNameTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONTNAMETAG_H
