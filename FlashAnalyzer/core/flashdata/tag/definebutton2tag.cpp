#include "definebutton2tag.h"

#include <iostream>

DefineButton2Tag::DefineButton2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_2_TAG, headerLength, dataLength)
{
}

void DefineButton2Tag::print() const
{
    std::cout << "DefineButton2Tag valid : " << valid() << std::endl;
    std::cout << "DefineButton2Tag code: " << code() << std::endl;
    std::cout << "DefineButton2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineButton2Tag totalLength: " << totalLength() << std::endl;
}
