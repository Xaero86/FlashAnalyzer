#ifndef DOACTIONTAG_H
#define DOACTIONTAG_H

#include "tag.h"

class DoActionTag : public Tag
{
public:
    DoActionTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DOACTIONTAG_H
