#include "placeobject3tag.h"

#include <iostream>

PlaceObject3Tag::PlaceObject3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, PLACE_OBJECT_3_TAG, headerLength, dataLength)
{
}

void PlaceObject3Tag::print() const
{
    std::cout << "PlaceObject3Tag valid : " << valid() << std::endl;
    std::cout << "PlaceObject3Tag code: " << code() << std::endl;
    std::cout << "PlaceObject3Tag dataLength: " << dataLength() << std::endl;
    std::cout << "PlaceObject3Tag totalLength: " << totalLength() << std::endl;
}
