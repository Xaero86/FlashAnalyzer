#include "placeobject2tag.h"

PlaceObject2Tag::PlaceObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PLACE_OBJECT_2_TAG, headerLength, dataLength)
{
}

std::string PlaceObject2Tag::tagType() const
{
	return "PlaceObject2";
}

std::string PlaceObject2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
