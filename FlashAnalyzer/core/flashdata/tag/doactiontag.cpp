#include "doactiontag.h"

DoActionTag::DoActionTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_ACTION_TAG, headerLength, dataLength)
{
}

std::string DoActionTag::tagType() const
{
	return "DoABC";
}

std::string DoActionTag::tagDescription() const
{
	return Tag::tagDescription();
}
