#ifndef PROTECTTAG_H
#define PROTECTTAG_H

#include "controltag.h"

class ProtectTag : public ControlTag
{
public:
    ProtectTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // PROTECTTAG_H
