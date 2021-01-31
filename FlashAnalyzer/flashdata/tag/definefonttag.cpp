#include "definefonttag.h"

DefineFontTag::DefineFontTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_TAG, headerLength, dataLength)
{
}

std::string DefineFontTag::tagType() const
{
	return "DefineFont";
}

std::string DefineFontTag::tagDescription() const
{
	return Tag::tagDescription();
}
