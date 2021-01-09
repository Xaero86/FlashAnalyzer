#ifndef SCRIPTLIMITSTAG_H
#define SCRIPTLIMITSTAG_H

#include "tag.h"

class ScriptLimitsTag : public Tag
{
public:
    ScriptLimitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // SCRIPTLIMITSTAG_H
