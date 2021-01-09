#ifndef DEFINEFONT4TAG_H
#define DEFINEFONT4TAG_H

#include "tag.h"

class DefineFont4Tag : public Tag
{
public:
    DefineFont4Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEFONT4TAG_H
