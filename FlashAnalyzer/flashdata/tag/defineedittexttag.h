#ifndef DEFINEEDITTEXTTAG_H
#define DEFINEEDITTEXTTAG_H

#include "tag.h"

class DefineEditTextTag : public Tag
{
public:
    DefineEditTextTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEEDITTEXTTAG_H
