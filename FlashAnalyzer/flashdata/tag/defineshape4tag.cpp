#include "defineshape4tag.h"

DefineShape4Tag::DefineShape4Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_4_TAG, headerLength, dataLength)
{
}

std::string DefineShape4Tag::tagType() const
{
	return "DefineShape4";
}

std::string DefineShape4Tag::tagDescription() const
{
	return Tag::tagDescription();
}
