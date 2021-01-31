#include "doinitactiontag.h"

DoInitActionTag::DoInitActionTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_INIT_ACTION_TAG, headerLength, dataLength)
{
}

std::string DoInitActionTag::tagType() const
{
	return "DoInitAction";
}

std::string DoInitActionTag::tagDescription() const
{
	return Tag::tagDescription();
}
