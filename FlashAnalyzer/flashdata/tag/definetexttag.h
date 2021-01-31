#ifndef DEFINETEXTTAG_H
#define DEFINETEXTTAG_H

#include "tag.h"

class DefineTextTag : public Tag
{
public:
    DefineTextTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINETEXTTAG_H
