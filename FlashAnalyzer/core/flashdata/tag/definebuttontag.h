#ifndef DEFINEBUTTONTAG_H
#define DEFINEBUTTONTAG_H

#include "definitiontag.h"

class DefineButtonTag : public DefinitionTag
{
public:
    DefineButtonTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
    
private:
    // ButtonRecord *
    // ActionRecord * //TODO
};

#endif // DEFINEBUTTONTAG_H
