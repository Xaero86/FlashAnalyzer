#ifndef DEFINEBUTTON2TAG_H
#define DEFINEBUTTON2TAG_H

#include "tag.h"

class DefineButton2Tag : public Tag
{
public:
    DefineButton2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEBUTTON2TAG_H
