#include "definebuttontag.h"

#include "tools.h"

DefineButtonTag::DefineButtonTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_BUTTON_TAG, headerLength, dataLength)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
}

std::string DefineButtonTag::tagType() const
{
	return "DefineButton";
}

std::string DefineButtonTag::tagDescription() const
{
	return Tag::tagDescription();
}
