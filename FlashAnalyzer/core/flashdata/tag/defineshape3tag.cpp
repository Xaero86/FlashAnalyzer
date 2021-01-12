#include "defineshape3tag.h"

DefineShape3Tag::DefineShape3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SHAPE_3_TAG, headerLength, dataLength)
{
}

std::string DefineShape3Tag::tagType() const
{
	return "DefineShape3";
}

std::string DefineShape3Tag::tagDescription() const
{
	return Tag::tagDescription();
}
