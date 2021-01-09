#ifndef ENABLEDEBUGGER2TAG_H
#define ENABLEDEBUGGER2TAG_H

#include "tag.h"

class EnableDebugger2Tag : public Tag
{
public:
    EnableDebugger2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // ENABLEDEBUGGER2TAG_H
