#include "definebutton2tag.h"

DefineButton2Tag::DefineButton2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_2_TAG, headerLength, dataLength)
{
}

std::string DefineButton2Tag::tagType() const
{
	return "DefineButton2";
}

std::string DefineButton2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
