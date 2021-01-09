#include "metadatatag.h"

#include <iostream>

MetadataTag::MetadataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, METADATA_TAG, headerLength, dataLength)
{
}

void MetadataTag::print() const
{
    std::cout << "MetadataTag valid : " << valid() << std::endl;
    std::cout << "MetadataTag code: " << code() << std::endl;
    std::cout << "MetadataTag dataLength: " << dataLength() << std::endl;
    std::cout << "MetadataTag totalLength: " << totalLength() << std::endl;
}
