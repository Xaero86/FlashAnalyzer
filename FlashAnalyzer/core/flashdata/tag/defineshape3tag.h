#ifndef DEFINESHAPE3TAG_H
#define DEFINESHAPE3TAG_H

#include "tag.h"

class DefineShape3Tag : public Tag
{
public:
    DefineShape3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINESHAPE3TAG_H
