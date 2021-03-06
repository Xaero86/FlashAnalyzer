#ifndef CONTROLTAG_H
#define CONTROLTAG_H

#include "tag.h"

class ControlTag : public Tag
{
public:
    ControlTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength);

	virtual std::string tagType() const override = 0;
	virtual std::string tagDescription() const override;
};

#endif // CONTROLTAG_H
