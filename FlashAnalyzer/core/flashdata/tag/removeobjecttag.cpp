#include "removeobjecttag.h"

#include <iostream>

#include "tools.h"

RemoveObjectTag::RemoveObjectTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, REMOVE_OBJECT_TAG, headerLength, dataLength),
 _characterId(0),
 _depth(0)
{
    uint32_t currentIndex = headerLength;
    _characterId = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_characterId);
    _depth = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_depth);
}

void RemoveObjectTag::print() const
{
    std::cout << "RemoveObjectTag valid : " << valid() << std::endl;
    std::cout << "RemoveObjectTag code: " << code() << std::endl;
    std::cout << "RemoveObjectTag dataLength: " << dataLength() << std::endl;
    std::cout << "RemoveObjectTag totalLength: " << totalLength() << std::endl;
}
