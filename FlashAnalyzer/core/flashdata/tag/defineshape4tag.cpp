#include "defineshape4tag.h"

#include <iostream>

DefineShape4Tag::DefineShape4Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_4_TAG, headerLength, dataLength)
{
}

void DefineShape4Tag::print() const
{
    std::cout << "DefineShape4Tag valid : " << valid() << std::endl;
    std::cout << "DefineShape4Tag code: " << code() << std::endl;
    std::cout << "DefineShape4Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineShape4Tag totalLength: " << totalLength() << std::endl;
}
