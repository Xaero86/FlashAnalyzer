#ifndef DEFINETEXT2TAG_H
#define DEFINETEXT2TAG_H

#include "tag.h"

class DefineText2Tag : public Tag
{
public:
    DefineText2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINETEXT2TAG_H
