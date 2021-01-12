#include "removeobject2tag.h"

RemoveObject2Tag::RemoveObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, REMOVE_OBJECT_2_TAG, headerLength, dataLength)
{
}

std::string RemoveObject2Tag::tagType() const
{
	return "RemoveObject2";
}

std::string RemoveObject2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
