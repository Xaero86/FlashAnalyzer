#include "placeobject2tag.h"

#include <iostream>

PlaceObject2Tag::PlaceObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PLACE_OBJECT_2_TAG, headerLength, dataLength)
{
}

void PlaceObject2Tag::print() const
{
    std::cout << "PlaceObject2Tag valid : " << valid() << std::endl;
    std::cout << "PlaceObject2Tag code: " << code() << std::endl;
    std::cout << "PlaceObject2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "PlaceObject2Tag totalLength: " << totalLength() << std::endl;
}
