#ifndef DEFINEBUTTONTAG_H
#define DEFINEBUTTONTAG_H

#include "definitiontag.h"

class DefineButtonTag : public DefinitionTag
{
public:
    DefineButtonTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEBUTTONTAG_H
