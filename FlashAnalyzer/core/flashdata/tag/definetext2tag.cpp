#include "definetext2tag.h"

#include <iostream>

DefineText2Tag::DefineText2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_TEXT_2_TAG, headerLength, dataLength)
{
}

void DefineText2Tag::print() const
{
    std::cout << "DefineText2Tag valid : " << valid() << std::endl;
    std::cout << "DefineText2Tag code: " << code() << std::endl;
    std::cout << "DefineText2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineText2Tag totalLength: " << totalLength() << std::endl;
}
