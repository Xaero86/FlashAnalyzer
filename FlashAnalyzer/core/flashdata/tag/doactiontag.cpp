#include "doactiontag.h"

#include <iostream>

DoActionTag::DoActionTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_ACTION_TAG, headerLength, dataLength)
{
}

void DoActionTag::print() const
{
    std::cout << "DoActionTag valid : " << valid() << std::endl;
    std::cout << "DoActionTag code: " << code() << std::endl;
    std::cout << "DoActionTag dataLength: " << dataLength() << std::endl;
    std::cout << "DoActionTag totalLength: " << totalLength() << std::endl;
}
