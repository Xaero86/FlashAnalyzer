#include "enabledebugger2tag.h"

EnableDebugger2Tag::EnableDebugger2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, ENABLE_DEBUGGER_2_TAG, headerLength, dataLength)
{
}

std::string EnableDebugger2Tag::tagType() const
{
	return "EnableDebugger2";
}

std::string EnableDebugger2Tag::tagDescription() const
{
	return ControlTag::tagDescription();
}
