#include "definefontinfo2tag.h"

DefineFontInfo2Tag::DefineFontInfo2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_INFO_2_TAG, headerLength, dataLength)
{
}

std::string DefineFontInfo2Tag::tagType() const
{
	return "DefineFontInfo2";
}

std::string DefineFontInfo2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
