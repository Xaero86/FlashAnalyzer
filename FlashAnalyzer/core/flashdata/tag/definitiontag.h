#ifndef DEFINITIONTAG_H
#define DEFINITIONTAG_H

#include "tag.h"

class DefinitionTag : public Tag
{
public:
    DefinitionTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength);
    
    uint16_t uid() const {return _uid;}
    
protected:
    uint16_t      _uid;
};

#endif // DEFINITIONTAG_H
