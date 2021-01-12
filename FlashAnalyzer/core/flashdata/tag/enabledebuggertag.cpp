#include "enabledebuggertag.h"

EnableDebuggerTag::EnableDebuggerTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, ENABLE_DEBUGGER_TAG, headerLength, dataLength)
{
}

std::string EnableDebuggerTag::tagType() const
{
	return "EnableDebugger";
}

std::string EnableDebuggerTag::tagDescription() const
{
	return Tag::tagDescription();
}
