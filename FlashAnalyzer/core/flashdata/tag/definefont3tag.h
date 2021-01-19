#ifndef DEFINEFONT3TAG_H
#define DEFINEFONT3TAG_H

#include "tag.h"

class DefineFont3Tag : public Tag
{
public:
    DefineFont3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEFONT3TAG_H
