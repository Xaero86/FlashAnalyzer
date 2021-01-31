#include "definebuttoncxformtag.h"

DefineButtonCxformTag::DefineButtonCxformTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_CXFORM_TAG, headerLength, dataLength)
{
}

std::string DefineButtonCxformTag::tagType() const
{
	return "DefineButtonCxform";
}

std::string DefineButtonCxformTag::tagDescription() const
{
	return Tag::tagDescription();
}
