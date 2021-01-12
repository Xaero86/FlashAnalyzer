#ifndef DEFINESCALINGGRIDTAG_H
#define DEFINESCALINGGRIDTAG_H

#include "tag.h"

class DefineScalingGridTag : public Tag
{
public:
    DefineScalingGridTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINESCALINGGRIDTAG_H
