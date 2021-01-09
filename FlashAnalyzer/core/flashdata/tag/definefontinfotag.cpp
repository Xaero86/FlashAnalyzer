#include "definefontinfotag.h"

#include <iostream>

DefineFontInfoTag::DefineFontInfoTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_INFO_TAG, headerLength, dataLength)
{
}

void DefineFontInfoTag::print() const
{
    std::cout << "DefineFontInfoTag valid : " << valid() << std::endl;
    std::cout << "DefineFontInfoTag code: " << code() << std::endl;
    std::cout << "DefineFontInfoTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFontInfoTag totalLength: " << totalLength() << std::endl;
}
