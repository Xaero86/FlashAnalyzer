#ifndef SETTABINDEXTAG_H
#define SETTABINDEXTAG_H

#include "controltag.h"

class SetTabIndexTag : public ControlTag
{
public:
    SetTabIndexTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // SETTABINDEXTAG_H
