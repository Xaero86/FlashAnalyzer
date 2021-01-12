#include "endtag.h"

EndTag::EndTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, END_TAG, headerLength, dataLength)
{
}

std::string EndTag::tagType() const
{
	return "End";
}

std::string EndTag::tagDescription() const
{
	return Tag::tagDescription();
}
