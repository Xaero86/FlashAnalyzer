#include "definefont4tag.h"

DefineFont4Tag::DefineFont4Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_4_TAG, headerLength, dataLength)
{
}

std::string DefineFont4Tag::tagType() const
{
	return "DefineFont4";
}

std::string DefineFont4Tag::tagDescription() const
{
	return Tag::tagDescription();
}
