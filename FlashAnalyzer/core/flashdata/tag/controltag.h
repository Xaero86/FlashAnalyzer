#ifndef CONTROLTAG_H
#define CONTROLTAG_H

#include "tag.h"

class ControlTag : public Tag
{
public:
    ControlTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength);
};

#endif // CONTROLTAG_H