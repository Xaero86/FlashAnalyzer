#include "importassetstag.h"

ImportAssetsTag::ImportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, IMPORT_ASSETS_TAG, headerLength, dataLength)
{
}

std::string ImportAssetsTag::tagType() const
{
	return "ImportAssets";
}

std::string ImportAssetsTag::tagDescription() const
{
	return ControlTag::tagDescription();
}
