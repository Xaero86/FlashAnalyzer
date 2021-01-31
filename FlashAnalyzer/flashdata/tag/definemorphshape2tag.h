#ifndef DEFINEMORPHSHAPE2TAG_H
#define DEFINEMORPHSHAPE2TAG_H

#include "tag.h"

class DefineMorphShape2Tag : public Tag
{
public:
    DefineMorphShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEMORPHSHAPE2TAG_H
