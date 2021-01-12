#ifndef DOINITACTIONTAG_H
#define DOINITACTIONTAG_H

#include "tag.h"

class DoInitActionTag : public Tag
{
public:
    DoInitActionTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DOINITACTIONTAG_H
