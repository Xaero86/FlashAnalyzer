#include "endtag.h"

#include <iostream>

EndTag::EndTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, END_TAG, headerLength, dataLength)
{
}

void EndTag::print() const
{
    std::cout << "EndTag valid : " << valid() << std::endl;
    std::cout << "EndTag code: " << code() << std::endl;
    std::cout << "EndTag dataLength: " << dataLength() << std::endl;
    std::cout << "EndTag totalLength: " << totalLength() << std::endl;
}
