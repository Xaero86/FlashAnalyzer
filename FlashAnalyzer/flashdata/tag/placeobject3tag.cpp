#include "placeobject3tag.h"

PlaceObject3Tag::PlaceObject3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PLACE_OBJECT_3_TAG, headerLength, dataLength)
{
}

std::string PlaceObject3Tag::tagType() const
{
	return "PlaceObject3";
}

std::string PlaceObject3Tag::tagDescription() const
{
	return Tag::tagDescription();
}
