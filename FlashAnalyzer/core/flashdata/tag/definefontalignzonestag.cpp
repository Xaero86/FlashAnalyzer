#include "definefontalignzonestag.h"

#include <iostream>

DefineFontAlignZonesTag::DefineFontAlignZonesTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_ALIGN_ZONES_TAG, headerLength, dataLength)
{
}

void DefineFontAlignZonesTag::print() const
{
    std::cout << "DefineFontAlignZonesTag valid : " << valid() << std::endl;
    std::cout << "DefineFontAlignZonesTag code: " << code() << std::endl;
    std::cout << "DefineFontAlignZonesTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFontAlignZonesTag totalLength: " << totalLength() << std::endl;
}
