#include "placeobjecttag.h"

#include "tools.h"

PlaceObjectTag::PlaceObjectTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, PLACE_OBJECT_TAG, headerLength, dataLength),
 _characterId(0),
 _depth(0),
 _matrix(),
 _colorTransform()
{
    uint32_t currentIndex = headerLength;
    _characterId = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_characterId);
    _depth = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_depth);
    
    _matrix.create(&_rawData[currentIndex], totalLength() - currentIndex);
    currentIndex += _matrix.dataSize();
        
    _colorTransform.create(&_rawData[currentIndex], totalLength() - currentIndex);
}

std::string PlaceObjectTag::tagType() const
{
	return "PlaceObject";
}

std::string PlaceObjectTag::tagDescription() const
{
	return Tag::tagDescription();
}
