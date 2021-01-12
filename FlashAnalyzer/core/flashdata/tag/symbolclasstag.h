#ifndef SYMBOLCLASSTAG_H
#define SYMBOLCLASSTAG_H

#include "tag.h"

class SymbolClassTag : public Tag
{
public:
    SymbolClassTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SYMBOLCLASSTAG_H
