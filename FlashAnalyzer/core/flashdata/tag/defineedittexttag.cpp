#include "defineedittexttag.h"

DefineEditTextTag::DefineEditTextTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_EDIT_TEXT_TAG, headerLength, dataLength)
{
}

std::string DefineEditTextTag::tagType() const
{
	return "DefineEditText";
}

std::string DefineEditTextTag::tagDescription() const
{
	return Tag::tagDescription();
}
