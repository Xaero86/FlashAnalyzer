#include "definetexttag.h"

DefineTextTag::DefineTextTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_TEXT_TAG, headerLength, dataLength)
{
}

std::string DefineTextTag::tagType() const
{
	return "DefineText";
}

std::string DefineTextTag::tagDescription() const
{
	return Tag::tagDescription();
}
