#include "setbackgroundcolortag.h"

SetBackgroundColorTag::SetBackgroundColorTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SET_BACKGROUND_COLOR_TAG, headerLength, dataLength),
 _color()
{
    uint32_t currentIndex = headerLength;
    _color.create(&_rawData[currentIndex], totalLength() - currentIndex);
}

std::string SetBackgroundColorTag::tagType() const
{
	return "SetBackgroundColor";
}

std::string SetBackgroundColorTag::tagDescription() const
{
	return Tag::tagDescription();
}
