#include "doabctag.h"

#include <iostream>

DoABCTag::DoABCTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_ABC_TAG, headerLength, dataLength)
{
}

void DoABCTag::print() const
{
    std::cout << "DoABCTag valid : " << valid() << std::endl;
    std::cout << "DoABCTag code: " << code() << std::endl;
    std::cout << "DoABCTag dataLength: " << dataLength() << std::endl;
    std::cout << "DoABCTag totalLength: " << totalLength() << std::endl;
}
