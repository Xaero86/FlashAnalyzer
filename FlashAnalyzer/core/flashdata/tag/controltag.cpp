#include "controltag.h"

ControlTag::ControlTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, code, headerLength, dataLength)
{
}
