#ifndef PROTECTTAG_H
#define PROTECTTAG_H

#include "tag.h"

class ProtectTag : public Tag
{
public:
    ProtectTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // PROTECTTAG_H
