#include "definefontinfotag.h"

DefineFontInfoTag::DefineFontInfoTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_INFO_TAG, headerLength, dataLength)
{
}

std::string DefineFontInfoTag::tagType() const
{
	return "DefineFontInfo";
}

std::string DefineFontInfoTag::tagDescription() const
{
	return Tag::tagDescription();
}
