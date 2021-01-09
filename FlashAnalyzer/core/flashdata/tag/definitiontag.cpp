#include "definitiontag.h"

DefinitionTag::DefinitionTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, code, headerLength, dataLength),
 _uid(0)
{
}
