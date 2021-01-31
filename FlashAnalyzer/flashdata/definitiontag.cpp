#include "definitiontag.h"

#include <sstream>

DefinitionTag::DefinitionTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, code, headerLength, dataLength),
 _uid(0)
{
}

std::string DefinitionTag::tagDescription() const
{
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Character id: " << _uid << std::endl;

	return description.str();
}
