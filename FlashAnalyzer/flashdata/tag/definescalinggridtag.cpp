#include "definescalinggridtag.h"

DefineScalingGridTag::DefineScalingGridTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SCALING_GRID_TAG, headerLength, dataLength)
{
}

std::string DefineScalingGridTag::tagType() const
{
	return "DefineScalingGrid";
}

std::string DefineScalingGridTag::tagDescription() const
{
	return Tag::tagDescription();
}
