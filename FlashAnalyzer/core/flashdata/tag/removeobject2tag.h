#ifndef REMOVEOBJECT2TAG_H
#define REMOVEOBJECT2TAG_H

#include "tag.h"

class RemoveObject2Tag : public Tag
{
public:
    RemoveObject2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // REMOVEOBJECT2TAG_H
