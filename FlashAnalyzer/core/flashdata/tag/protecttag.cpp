#include "protecttag.h"

#include <iostream>

ProtectTag::ProtectTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PROTECT_TAG, headerLength, dataLength)
{
}

void ProtectTag::print() const
{
    std::cout << "ProtectTag valid : " << valid() << std::endl;
    std::cout << "ProtectTag code: " << code() << std::endl;
    std::cout << "ProtectTag dataLength: " << dataLength() << std::endl;
    std::cout << "ProtectTag totalLength: " << totalLength() << std::endl;
}
