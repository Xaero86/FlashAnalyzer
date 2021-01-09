#ifndef DEFINEMORPHSHAPE2TAG_H
#define DEFINEMORPHSHAPE2TAG_H

#include "tag.h"

class DefineMorphShape2Tag : public Tag
{
public:
    DefineMorphShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEMORPHSHAPE2TAG_H
