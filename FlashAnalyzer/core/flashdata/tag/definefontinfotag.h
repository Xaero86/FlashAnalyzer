#ifndef DEFINEFONTINFOTAG_H
#define DEFINEFONTINFOTAG_H

#include "tag.h"

class DefineFontInfoTag : public Tag
{
public:
    DefineFontInfoTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONTINFOTAG_H
