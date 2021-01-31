#ifndef DEFINESHAPE2TAG_H
#define DEFINESHAPE2TAG_H

#include "tag.h"

class DefineShape2Tag : public Tag
{
public:
    DefineShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINESHAPE2TAG_H
