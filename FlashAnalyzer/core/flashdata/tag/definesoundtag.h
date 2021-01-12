#ifndef DEFINESOUNDTAG_H
#define DEFINESOUNDTAG_H

#include "tag.h"

class DefineSoundTag : public Tag
{
public:
    DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINESOUNDTAG_H
