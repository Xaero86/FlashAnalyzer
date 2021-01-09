#ifndef PLACEOBJECT2TAG_H
#define PLACEOBJECT2TAG_H

#include "tag.h"

class PlaceObject2Tag : public Tag
{
public:
    PlaceObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // PLACEOBJECT2TAG_H