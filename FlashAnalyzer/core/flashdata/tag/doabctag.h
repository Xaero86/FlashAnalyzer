#ifndef DOABCTAG_H
#define DOABCTAG_H

#include "tag.h"

class DoABCTag : public Tag
{
public:
    DoABCTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DOABCTAG_H
