#ifndef STARTSOUNDTAG_H
#define STARTSOUNDTAG_H

#include "tag.h"

class StartSoundTag : public Tag
{
public:
    StartSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // STARTSOUNDTAG_H
