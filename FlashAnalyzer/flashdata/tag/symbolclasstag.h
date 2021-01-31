#ifndef SYMBOLCLASSTAG_H
#define SYMBOLCLASSTAG_H

#include "controltag.h"

class SymbolClassTag : public ControlTag
{
public:
    SymbolClassTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // SYMBOLCLASSTAG_H
