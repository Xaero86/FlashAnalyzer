#ifndef DEFINEFONT3TAG_H
#define DEFINEFONT3TAG_H

#include "tag.h"

class DefineFont3Tag : public Tag
{
public:
    DefineFont3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONT3TAG_H
