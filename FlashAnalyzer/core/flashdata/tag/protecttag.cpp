#include "protecttag.h"

ProtectTag::ProtectTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PROTECT_TAG, headerLength, dataLength)
{
}

std::string ProtectTag::tagType() const
{
	return "Protect";
}

std::string ProtectTag::tagDescription() const
{
	return Tag::tagDescription();
}
