#include "definefontnametag.h"

DefineFontNameTag::DefineFontNameTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_NAME_TAG, headerLength, dataLength)
{
}

std::string DefineFontNameTag::tagType() const
{
	return "DefineFontName";
}

std::string DefineFontNameTag::tagDescription() const
{
	return Tag::tagDescription();
}
