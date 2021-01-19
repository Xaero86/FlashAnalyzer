#ifndef DOINITACTIONTAG_H
#define DOINITACTIONTAG_H

#include "tag.h"

class DoInitActionTag : public Tag
{
public:
    DoInitActionTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DOINITACTIONTAG_H
