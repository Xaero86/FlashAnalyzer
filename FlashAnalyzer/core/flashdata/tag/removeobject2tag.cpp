#include "removeobject2tag.h"

#include <iostream>

RemoveObject2Tag::RemoveObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, REMOVE_OBJECT_2_TAG, headerLength, dataLength)
{
}

void RemoveObject2Tag::print() const
{
    std::cout << "RemoveObject2Tag valid : " << valid() << std::endl;
    std::cout << "RemoveObject2Tag code: " << code() << std::endl;
    std::cout << "RemoveObject2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "RemoveObject2Tag totalLength: " << totalLength() << std::endl;
}
