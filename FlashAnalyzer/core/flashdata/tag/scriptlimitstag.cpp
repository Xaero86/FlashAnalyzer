#include "scriptlimitstag.h"

#include <iostream>

ScriptLimitsTag::ScriptLimitsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SCRIPT_LIMITS_TAG, headerLength, dataLength)
{
}

void ScriptLimitsTag::print() const
{
    std::cout << "ScriptLimitsTag valid : " << valid() << std::endl;
    std::cout << "ScriptLimitsTag code: " << code() << std::endl;
    std::cout << "ScriptLimitsTag dataLength: " << dataLength() << std::endl;
    std::cout << "ScriptLimitsTag totalLength: " << totalLength() << std::endl;
}
