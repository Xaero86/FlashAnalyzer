#include "metadatatag.h"

MetadataTag::MetadataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, METADATA_TAG, headerLength, dataLength)
{
}

std::string MetadataTag::tagType() const
{
	return "Metadata";
}

std::string MetadataTag::tagDescription() const
{
	return Tag::tagDescription();
}
