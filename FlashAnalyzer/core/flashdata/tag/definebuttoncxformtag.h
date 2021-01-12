#ifndef DEFINEBUTTONCXFORMTAG_H
#define DEFINEBUTTONCXFORMTAG_H

#include "tag.h"

class DefineButtonCxformTag : public Tag
{
public:
    DefineButtonCxformTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINEBUTTONCXFORMTAG_H
