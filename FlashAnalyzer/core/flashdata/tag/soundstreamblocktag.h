#ifndef SOUNDSTREAMBLOCKTAG_H
#define SOUNDSTREAMBLOCKTAG_H

#include "tag.h"

class SoundStreamBlockTag : public Tag
{
public:
    SoundStreamBlockTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SOUNDSTREAMBLOCKTAG_H
