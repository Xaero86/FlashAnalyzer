#ifndef DEFINESPRITETAG_H
#define DEFINESPRITETAG_H

#include "definitiontag.h"

class DefineSpriteTag : public DefinitionTag
{
public:
    DefineSpriteTag(const char* source, uint32_t headerLength, uint32_t dataLength, SWFFile* swfFile);
    
    void print() const;
    
private:
    uint16_t       _frameCount;
    Tag::tags_t    _tags;
};

#endif // DEFINESPRITETAG_H
