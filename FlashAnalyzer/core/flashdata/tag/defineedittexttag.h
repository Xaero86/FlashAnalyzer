#ifndef DEFINEEDITTEXTTAG_H
#define DEFINEEDITTEXTTAG_H

#include "tag.h"

class DefineEditTextTag : public Tag
{
public:
    DefineEditTextTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEEDITTEXTTAG_H
