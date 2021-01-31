#ifndef DEFINEFONTNAMETAG_H
#define DEFINEFONTNAMETAG_H

#include "tag.h"

class DefineFontNameTag : public Tag
{
public:
    DefineFontNameTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEFONTNAMETAG_H
