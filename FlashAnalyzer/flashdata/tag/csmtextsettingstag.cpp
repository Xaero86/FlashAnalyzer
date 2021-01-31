#include "csmtextsettingstag.h"

CSMTextSettingsTag::CSMTextSettingsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, CSM_TEXT_SETTINGS_TAG, headerLength, dataLength)
{
}

std::string CSMTextSettingsTag::tagType() const
{
	return "CSMTextSettings";
}

std::string CSMTextSettingsTag::tagDescription() const
{
	return Tag::tagDescription();
}
