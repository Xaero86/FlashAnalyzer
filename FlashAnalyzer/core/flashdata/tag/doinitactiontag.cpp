#include "doinitactiontag.h"

#include <iostream>

DoInitActionTag::DoInitActionTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_INIT_ACTION_TAG, headerLength, dataLength)
{
}

void DoInitActionTag::print() const
{
    std::cout << "DoInitActionTag valid : " << valid() << std::endl;
    std::cout << "DoInitActionTag code: " << code() << std::endl;
    std::cout << "DoInitActionTag dataLength: " << dataLength() << std::endl;
    std::cout << "DoInitActionTag totalLength: " << totalLength() << std::endl;
}
