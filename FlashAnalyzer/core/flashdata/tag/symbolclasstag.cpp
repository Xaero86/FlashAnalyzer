#include "symbolclasstag.h"

#include <iostream>

SymbolClassTag::SymbolClassTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SYMBOL_CLASS_TAG, headerLength, dataLength)
{
}

void SymbolClassTag::print() const
{
    std::cout << "SymbolClassTag valid : " << valid() << std::endl;
    std::cout << "SymbolClassTag code: " << code() << std::endl;
    std::cout << "SymbolClassTag dataLength: " << dataLength() << std::endl;
    std::cout << "SymbolClassTag totalLength: " << totalLength() << std::endl;
}
