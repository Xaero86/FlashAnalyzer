#ifndef STARTSOUND2TAG_H
#define STARTSOUND2TAG_H

#include "tag.h"

class StartSound2Tag : public Tag
{
public:
    StartSound2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // STARTSOUND2TAG_H
