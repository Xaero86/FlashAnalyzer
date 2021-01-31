#include "defineshape2tag.h"

DefineShape2Tag::DefineShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_2_TAG, headerLength, dataLength)
{
}

std::string DefineShape2Tag::tagType() const
{
	return "DefineShape2";
}

std::string DefineShape2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
