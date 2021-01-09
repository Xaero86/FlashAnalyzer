#include "defineedittexttag.h"

#include <iostream>

DefineEditTextTag::DefineEditTextTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_EDIT_TEXT_TAG, headerLength, dataLength)
{
}

void DefineEditTextTag::print() const
{
    std::cout << "DefineEditTextTag valid : " << valid() << std::endl;
    std::cout << "DefineEditTextTag code: " << code() << std::endl;
    std::cout << "DefineEditTextTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineEditTextTag totalLength: " << totalLength() << std::endl;
}
