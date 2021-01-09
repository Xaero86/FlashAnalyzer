#include "definebuttontag.h"

#include <iostream>

#include "tools.h"

DefineButtonTag::DefineButtonTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_BUTTON_TAG, headerLength, dataLength)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
}

void DefineButtonTag::print() const
{
    std::cout << "DefineButtonTag valid : " << valid() << std::endl;
    std::cout << "DefineButtonTag code: " << code() << std::endl;
    std::cout << "DefineButtonTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineButtonTag totalLength: " << totalLength() << std::endl;
}
