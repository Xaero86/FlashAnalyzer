#ifndef SOUNDSTREAMHEAD2TAG_H
#define SOUNDSTREAMHEAD2TAG_H

#include "tag.h"

class SoundStreamHead2Tag : public Tag
{
public:
    SoundStreamHead2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SOUNDSTREAMHEAD2TAG_H
