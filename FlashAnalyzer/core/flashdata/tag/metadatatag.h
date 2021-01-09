#ifndef METADATATAG_H
#define METADATATAG_H

#include "tag.h"

class MetadataTag : public Tag
{
public:
    MetadataTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // METADATATAG_H
