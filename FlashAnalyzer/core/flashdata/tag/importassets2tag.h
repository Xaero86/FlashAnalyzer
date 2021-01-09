#ifndef IMPORTASSETS2TAG_H
#define IMPORTASSETS2TAG_H

#include "tag.h"

class ImportAssets2Tag : public Tag
{
public:
    ImportAssets2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // IMPORTASSETS2TAG_H
