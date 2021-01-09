#include "fileattributestag.h"

#include <iostream>

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

void FileAttributesTag::print() const
{
    std::cout << "FileAttributesTag valid : " << valid() << std::endl;
    std::cout << "FileAttributesTag code: " << code() << std::endl;
    std::cout << "FileAttributesTag dataLength: " << dataLength() << std::endl;
    std::cout << "FileAttributesTag totalLength: " << totalLength() << std::endl;
}
