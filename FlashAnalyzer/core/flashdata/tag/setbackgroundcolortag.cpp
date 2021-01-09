#include "setbackgroundcolortag.h"

#include <iostream>

SetBackgroundColorTag::SetBackgroundColorTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SET_BACKGROUND_COLOR_TAG, headerLength, dataLength),
 _color()
{
    uint32_t currentIndex = headerLength;
    _color.create(&_rawData[currentIndex], totalLength() - currentIndex);
}

void SetBackgroundColorTag::print() const
{
    std::cout << "SetBackgroundColorTag valid : " << valid() << std::endl;
    std::cout << "SetBackgroundColorTag code: " << code() << std::endl;
    std::cout << "SetBackgroundColorTag dataLength: " << dataLength() << std::endl;
    std::cout << "SetBackgroundColorTag totalLength: " << totalLength() << std::endl;
}
