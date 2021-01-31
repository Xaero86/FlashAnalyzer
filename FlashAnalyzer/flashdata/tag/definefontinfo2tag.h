#ifndef DEFINEFONTINFO2TAG_H
#define DEFINEFONTINFO2TAG_H

#include "tag.h"

class DefineFontInfo2Tag : public Tag
{
public:
    DefineFontInfo2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEFONTINFO2TAG_H
