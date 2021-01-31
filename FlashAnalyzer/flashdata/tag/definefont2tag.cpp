#include "definefont2tag.h"

DefineFont2Tag::DefineFont2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_2_TAG, headerLength, dataLength)
{
}

std::string DefineFont2Tag::tagType() const
{
	return "DefineFont2";
}

std::string DefineFont2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
