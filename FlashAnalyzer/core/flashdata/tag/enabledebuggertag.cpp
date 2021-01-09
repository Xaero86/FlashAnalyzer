#include "enabledebuggertag.h"

#include <iostream>

EnableDebuggerTag::EnableDebuggerTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, ENABLE_DEBUGGER_TAG, headerLength, dataLength)
{
}

void EnableDebuggerTag::print() const
{
    std::cout << "EnableDebuggerTag valid : " << valid() << std::endl;
    std::cout << "EnableDebuggerTag code: " << code() << std::endl;
    std::cout << "EnableDebuggerTag dataLength: " << dataLength() << std::endl;
    std::cout << "EnableDebuggerTag totalLength: " << totalLength() << std::endl;
}
