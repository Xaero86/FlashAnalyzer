#include "definemorphshapetag.h"

DefineMorphShapeTag::DefineMorphShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_MORPH_SHAPE_TAG, headerLength, dataLength)
{
}

std::string DefineMorphShapeTag::tagType() const
{
	return "DefineMorphShape";
}

std::string DefineMorphShapeTag::tagDescription() const
{
	return Tag::tagDescription();
}
