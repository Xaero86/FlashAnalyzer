#ifndef SCRIPTLIMITSTAG_H
#define SCRIPTLIMITSTAG_H

#include "tag.h"

class ScriptLimitsTag : public Tag
{
public:
    ScriptLimitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SCRIPTLIMITSTAG_H
