#ifndef PLACEOBJECT3TAG_H
#define PLACEOBJECT3TAG_H

#include "tag.h"

class PlaceObject3Tag : public Tag
{
public:
    PlaceObject3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // PLACEOBJECT3TAG_H
