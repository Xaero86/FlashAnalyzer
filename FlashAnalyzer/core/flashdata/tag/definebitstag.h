#ifndef DEFINEBITSTAG_H
#define DEFINEBITSTAG_H

#include "imagetag.h"

class DefineBitsTag : public ImageTag
{
public:
    DefineBitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // DEFINEBITSTAG_H
