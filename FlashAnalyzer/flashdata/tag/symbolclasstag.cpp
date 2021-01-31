#include "symbolclasstag.h"

SymbolClassTag::SymbolClassTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SYMBOL_CLASS_TAG, headerLength, dataLength)
{
}

std::string SymbolClassTag::tagType() const
{
	return "SymbolClass";
}

std::string SymbolClassTag::tagDescription() const
{
	return ControlTag::tagDescription();
}
