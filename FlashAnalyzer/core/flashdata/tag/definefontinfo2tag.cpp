#include "definefontinfo2tag.h"

#include <iostream>

DefineFontInfo2Tag::DefineFontInfo2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_INFO_2_TAG, headerLength, dataLength)
{
}

void DefineFontInfo2Tag::print() const
{
    std::cout << "DefineFontInfo2Tag valid : " << valid() << std::endl;
    std::cout << "DefineFontInfo2Tag code: " << code() << std::endl;
    std::cout << "DefineFontInfo2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFontInfo2Tag totalLength: " << totalLength() << std::endl;
}
