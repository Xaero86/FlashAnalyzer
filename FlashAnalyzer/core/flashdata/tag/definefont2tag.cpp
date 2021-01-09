#include "definefont2tag.h"

#include <iostream>

DefineFont2Tag::DefineFont2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_2_TAG, headerLength, dataLength)
{
}

void DefineFont2Tag::print() const
{
    std::cout << "DefineFont2Tag valid : " << valid() << std::endl;
    std::cout << "DefineFont2Tag code: " << code() << std::endl;
    std::cout << "DefineFont2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFont2Tag totalLength: " << totalLength() << std::endl;
}
