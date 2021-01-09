#ifndef DEFINEFONTTAG_H
#define DEFINEFONTTAG_H

#include "tag.h"

class DefineFontTag : public Tag
{
public:
    DefineFontTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONTTAG_H
