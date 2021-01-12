#include "defineshapetag.h"

#include "tools.h"

DefineShapeTag::DefineShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_SHAPE_TAG, headerLength, dataLength),
 _shapeBounds()
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _shapeBounds.create(&_rawData[currentIndex], totalLength() - currentIndex);
}

std::string DefineShapeTag::tagType() const
{
	return "DefineShape";
}

std::string DefineShapeTag::tagDescription() const
{
	return Tag::tagDescription();
}
