#include "definetext2tag.h"

DefineText2Tag::DefineText2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_TEXT_2_TAG, headerLength, dataLength)
{
}

std::string DefineText2Tag::tagType() const
{
	return "DefineText2";
}

std::string DefineText2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
