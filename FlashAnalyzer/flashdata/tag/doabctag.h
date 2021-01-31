#ifndef DOABCTAG_H
#define DOABCTAG_H

#include "tag.h"

class DoABCTag : public Tag
{
public:
    DoABCTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DOABCTAG_H
