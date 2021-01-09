#include "definebuttoncxformtag.h"

#include <iostream>

DefineButtonCxformTag::DefineButtonCxformTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_CXFORM_TAG, headerLength, dataLength)
{
}

void DefineButtonCxformTag::print() const
{
    std::cout << "DefineButtonCxformTag valid : " << valid() << std::endl;
    std::cout << "DefineButtonCxformTag code: " << code() << std::endl;
    std::cout << "DefineButtonCxformTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineButtonCxformTag totalLength: " << totalLength() << std::endl;
}
