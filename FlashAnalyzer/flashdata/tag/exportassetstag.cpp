#include "exportassetstag.h"

ExportAssetsTag::ExportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, EXPORT_ASSETS_TAG, headerLength, dataLength)
{
}

std::string ExportAssetsTag::tagType() const
{
	return "ExportAssets";
}

std::string ExportAssetsTag::tagDescription() const
{
	return ControlTag::tagDescription();
}
