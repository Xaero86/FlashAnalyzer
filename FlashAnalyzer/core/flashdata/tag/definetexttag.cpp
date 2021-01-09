#include "definetexttag.h"

#include <iostream>

DefineTextTag::DefineTextTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_TEXT_TAG, headerLength, dataLength)
{
}

void DefineTextTag::print() const
{
    std::cout << "DefineTextTag valid : " << valid() << std::endl;
    std::cout << "DefineTextTag code: " << code() << std::endl;
    std::cout << "DefineTextTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineTextTag totalLength: " << totalLength() << std::endl;
}
