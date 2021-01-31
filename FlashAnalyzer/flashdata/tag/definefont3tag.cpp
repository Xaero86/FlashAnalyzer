#include "definefont3tag.h"

DefineFont3Tag::DefineFont3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_3_TAG, headerLength, dataLength)
{
}

std::string DefineFont3Tag::tagType() const
{
	return "DefineFont3";
}

std::string DefineFont3Tag::tagDescription() const
{
	return Tag::tagDescription();
}
