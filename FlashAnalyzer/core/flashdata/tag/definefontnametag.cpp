#include "definefontnametag.h"

#include <iostream>

DefineFontNameTag::DefineFontNameTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_NAME_TAG, headerLength, dataLength)
{
}

void DefineFontNameTag::print() const
{
    std::cout << "DefineFontNameTag valid : " << valid() << std::endl;
    std::cout << "DefineFontNameTag code: " << code() << std::endl;
    std::cout << "DefineFontNameTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFontNameTag totalLength: " << totalLength() << std::endl;
}
