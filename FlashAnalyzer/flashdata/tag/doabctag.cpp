#include "doabctag.h"

DoABCTag::DoABCTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DO_ABC_TAG, headerLength, dataLength)
{
}

std::string DoABCTag::tagType() const
{
	return "DoABC";
}

std::string DoABCTag::tagDescription() const
{
	return Tag::tagDescription();
}
