#include "importassetstag.h"

#include <iostream>

ImportAssetsTag::ImportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, IMPORT_ASSETS_TAG, headerLength, dataLength)
{
}

void ImportAssetsTag::print() const
{
    std::cout << "ImportAssetsTag valid : " << valid() << std::endl;
    std::cout << "ImportAssetsTag code: " << code() << std::endl;
    std::cout << "ImportAssetsTag dataLength: " << dataLength() << std::endl;
    std::cout << "ImportAssetsTag totalLength: " << totalLength() << std::endl;
}
