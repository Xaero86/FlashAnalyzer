#include "definemorphshape2tag.h"

DefineMorphShape2Tag::DefineMorphShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_MORPH_SHAPE_2_TAG, headerLength, dataLength)
{
}

std::string DefineMorphShape2Tag::tagType() const
{
	return "DefineMorphShape2";
}

std::string DefineMorphShape2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
