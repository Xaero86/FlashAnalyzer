#ifndef DEFINESHAPE4TAG_H
#define DEFINESHAPE4TAG_H

#include "tag.h"

class DefineShape4Tag : public Tag
{
public:
    DefineShape4Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINESHAPE4TAG_H
