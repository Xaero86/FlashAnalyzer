#include "definefont4tag.h"

#include <iostream>

DefineFont4Tag::DefineFont4Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_4_TAG, headerLength, dataLength)
{
}

void DefineFont4Tag::print() const
{
    std::cout << "DefineFont4Tag valid : " << valid() << std::endl;
    std::cout << "DefineFont4Tag code: " << code() << std::endl;
    std::cout << "DefineFont4Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFont4Tag totalLength: " << totalLength() << std::endl;
}
