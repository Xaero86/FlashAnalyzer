#include "definefonttag.h"

#include <iostream>

DefineFontTag::DefineFontTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_TAG, headerLength, dataLength)
{
}

void DefineFontTag::print() const
{
    std::cout << "DefineFontTag valid : " << valid() << std::endl;
    std::cout << "DefineFontTag code: " << code() << std::endl;
    std::cout << "DefineFontTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFontTag totalLength: " << totalLength() << std::endl;
}
