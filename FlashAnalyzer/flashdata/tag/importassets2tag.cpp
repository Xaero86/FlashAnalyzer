#include "importassets2tag.h"

ImportAssets2Tag::ImportAssets2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, IMPORT_ASSETS_2_TAG, headerLength, dataLength)
{
}

std::string ImportAssets2Tag::tagType() const
{
	return "ImportAssets2";
}

std::string ImportAssets2Tag::tagDescription() const
{
	return ControlTag::tagDescription();
}
