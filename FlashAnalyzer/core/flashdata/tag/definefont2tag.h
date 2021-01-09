#ifndef DEFINEFONT2TAG_H
#define DEFINEFONT2TAG_H

#include "tag.h"

class DefineFont2Tag : public Tag
{
public:
    DefineFont2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONT2TAG_H
