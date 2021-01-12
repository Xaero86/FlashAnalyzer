#include "scriptlimitstag.h"

ScriptLimitsTag::ScriptLimitsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SCRIPT_LIMITS_TAG, headerLength, dataLength)
{
}

std::string ScriptLimitsTag::tagType() const
{
	return "ScriptLimits";
}

std::string ScriptLimitsTag::tagDescription() const
{
	return Tag::tagDescription();
}
