#include "defineshape2tag.h"

#include <iostream>

DefineShape2Tag::DefineShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_2_TAG, headerLength, dataLength)
{
}

void DefineShape2Tag::print() const
{
    std::cout << "DefineShape2Tag valid : " << valid() << std::endl;
    std::cout << "DefineShape2Tag code: " << code() << std::endl;
    std::cout << "DefineShape2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineShape2Tag totalLength: " << totalLength() << std::endl;
}
