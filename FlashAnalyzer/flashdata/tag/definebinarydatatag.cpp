#include "definebinarydatatag.h"

DefineBinaryDataTag::DefineBinaryDataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BINARY_DATA_TAG, headerLength, dataLength)
{
}

std::string DefineBinaryDataTag::tagType() const
{
	return "DefineBinaryData";
}

std::string DefineBinaryDataTag::tagDescription() const
{
	return Tag::tagDescription();
}
