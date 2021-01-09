#ifndef ENDTAG_H
#define ENDTAG_H

#include "controltag.h"

class EndTag : public ControlTag
{
public:
    EndTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // ENDTAG_H
