#include "csmtextsettingstag.h"

#include <iostream>

CSMTextSettingsTag::CSMTextSettingsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, CSM_TEXT_SETTINGS_TAG, headerLength, dataLength)
{
}

void CSMTextSettingsTag::print() const
{
    std::cout << "CSMTextSettingsTag valid : " << valid() << std::endl;
    std::cout << "CSMTextSettingsTag code: " << code() << std::endl;
    std::cout << "CSMTextSettingsTag dataLength: " << dataLength() << std::endl;
    std::cout << "CSMTextSettingsTag totalLength: " << totalLength() << std::endl;
}
