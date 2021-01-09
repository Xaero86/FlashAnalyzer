#include "importassets2tag.h"

#include <iostream>

ImportAssets2Tag::ImportAssets2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, IMPORT_ASSETS_2_TAG, headerLength, dataLength)
{
}

void ImportAssets2Tag::print() const
{
    std::cout << "ImportAssets2Tag valid : " << valid() << std::endl;
    std::cout << "ImportAssets2Tag code: " << code() << std::endl;
    std::cout << "ImportAssets2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "ImportAssets2Tag totalLength: " << totalLength() << std::endl;
}
