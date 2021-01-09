#include "enabledebugger2tag.h"

#include <iostream>

EnableDebugger2Tag::EnableDebugger2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, ENABLE_DEBUGGER_2_TAG, headerLength, dataLength)
{
}

void EnableDebugger2Tag::print() const
{
    std::cout << "EnableDebugger2Tag valid : " << valid() << std::endl;
    std::cout << "EnableDebugger2Tag code: " << code() << std::endl;
    std::cout << "EnableDebugger2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "EnableDebugger2Tag totalLength: " << totalLength() << std::endl;
}
