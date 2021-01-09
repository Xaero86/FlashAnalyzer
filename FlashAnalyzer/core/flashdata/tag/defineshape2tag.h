#ifndef DEFINESHAPE2TAG_H
#define DEFINESHAPE2TAG_H

#include "tag.h"

class DefineShape2Tag : public Tag
{
public:
    DefineShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINESHAPE2TAG_H