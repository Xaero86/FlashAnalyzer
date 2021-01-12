#include "definefontalignzonestag.h"

DefineFontAlignZonesTag::DefineFontAlignZonesTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_FONT_ALIGN_ZONES_TAG, headerLength, dataLength)
{
}

std::string DefineFontAlignZonesTag::tagType() const
{
	return "DefineFontAlignZones";
}

std::string DefineFontAlignZonesTag::tagDescription() const
{
	return Tag::tagDescription();
}
