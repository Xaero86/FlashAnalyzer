#include "symbolclasstag.h"

SymbolClassTag::SymbolClassTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SYMBOL_CLASS_TAG, headerLength, dataLength)
{
}

std::string SymbolClassTag::tagType() const
{
	return "SymbolClass";
}

std::string SymbolClassTag::tagDescription() const
{
	return Tag::tagDescription();
}
