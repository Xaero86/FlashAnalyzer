#include "defineshape3tag.h"

#include <iostream>

DefineShape3Tag::DefineShape3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_3_TAG, headerLength, dataLength)
{
}

void DefineShape3Tag::print() const
{
    std::cout << "DefineShape3Tag valid : " << valid() << std::endl;
    std::cout << "DefineShape3Tag code: " << code() << std::endl;
    std::cout << "DefineShape3Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineShape3Tag totalLength: " << totalLength() << std::endl;
}
