#ifndef SCRIPTLIMITSTAG_H
#define SCRIPTLIMITSTAG_H

#include "controltag.h"

class ScriptLimitsTag : public ControlTag
{
public:
    ScriptLimitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // SCRIPTLIMITSTAG_H
