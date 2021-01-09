#include "settabindextag.h"

#include <iostream>

SetTabIndexTag::SetTabIndexTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SET_TAB_INDEX_TAG, headerLength, dataLength)
{
}

void SetTabIndexTag::print() const
{
    std::cout << "SetTabIndexTag valid : " << valid() << std::endl;
    std::cout << "SetTabIndexTag code: " << code() << std::endl;
    std::cout << "SetTabIndexTag dataLength: " << dataLength() << std::endl;
    std::cout << "SetTabIndexTag totalLength: " << totalLength() << std::endl;
}
