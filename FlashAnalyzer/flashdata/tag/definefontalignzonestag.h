#ifndef DEFINEFONTALIGNZONESTAG_H
#define DEFINEFONTALIGNZONESTAG_H

#include "tag.h"

class DefineFontAlignZonesTag : public Tag
{
public:
    DefineFontAlignZonesTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEFONTALIGNZONESTAG_H
