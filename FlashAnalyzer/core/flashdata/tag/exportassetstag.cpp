#include "exportassetstag.h"

#include <iostream>

ExportAssetsTag::ExportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, EXPORT_ASSETS_TAG, headerLength, dataLength)
{
}

void ExportAssetsTag::print() const
{
    std::cout << "ExportAssetsTag valid : " << valid() << std::endl;
    std::cout << "ExportAssetsTag code: " << code() << std::endl;
    std::cout << "ExportAssetsTag dataLength: " << dataLength() << std::endl;
    std::cout << "ExportAssetsTag totalLength: " << totalLength() << std::endl;
}
