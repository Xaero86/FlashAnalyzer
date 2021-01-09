#include "definefont3tag.h"

#include <iostream>

DefineFont3Tag::DefineFont3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_3_TAG, headerLength, dataLength)
{
}

void DefineFont3Tag::print() const
{
    std::cout << "DefineFont3Tag valid : " << valid() << std::endl;
    std::cout << "DefineFont3Tag code: " << code() << std::endl;
    std::cout << "DefineFont3Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineFont3Tag totalLength: " << totalLength() << std::endl;
}
