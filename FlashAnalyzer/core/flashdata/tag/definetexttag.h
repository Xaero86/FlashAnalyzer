#ifndef DEFINETEXTTAG_H
#define DEFINETEXTTAG_H

#include "tag.h"

class DefineTextTag : public Tag
{
public:
    DefineTextTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINETEXTTAG_H
