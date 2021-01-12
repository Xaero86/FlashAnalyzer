#include "fileattributestag.h"

#include <sstream>

FileAttributesTag::FileAttributesTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, FILE_ATTRIBUTES_TAG, headerLength, dataLength),
 _hasMetaData(false),
 _hasAS3(false),
 _noCrossDomainCache(false),
 _useNetwork(false)
{
    unsigned char data = (unsigned char) _rawData[0];

    _hasMetaData = ((data & 0x10) == 0x10);
    _hasAS3 = ((data & 0x8) == 0x8);
    _noCrossDomainCache = ((data & 0x4) == 0x4);
    _useNetwork = ((data & 0x1) == 0x1);
}

std::string FileAttributesTag::tagType() const
{
	return "FileAttributes";
}

std::string FileAttributesTag::tagDescription() const
{
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Has metadata: " << _hasMetaData << std::endl;
	description << "Has AS3: " << _hasAS3 << std::endl;
	description << "No cress domain cache: " << _noCrossDomainCache << std::endl;
	description << "Use network: " << _useNetwork << std::endl;

	return description.str();
}
