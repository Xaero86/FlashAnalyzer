#include "definebitstag.h"

#include <iostream>

#include "tools.h"

DefineBitsTag::DefineBitsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ImageTag(source, DEFINE_BITS_TAG, headerLength, dataLength)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _imageData = &_rawData[currentIndex];
    _imageDataSize = totalLength() - currentIndex;
    
    _imageType = ImageType::JPEG;
    
    bool erroneousJpeg = (((unsigned char) _imageData[0] == 0xFF) && ((unsigned char) _imageData[1] == 0xD9) &&
                          ((unsigned char) _imageData[2] == 0xFF) && ((unsigned char) _imageData[3] == 0xD8));

    if (erroneousJpeg)
    {
        // skip erroneous data
        _imageData = &_imageData[4];
        _imageDataSize -= 4;
    }
}

void DefineBitsTag::print() const
{
    std::cout << "DefineBitsTag valid : " << valid() << std::endl;
    std::cout << "DefineBitsTag code: " << code() << std::endl;
    std::cout << "DefineBitsTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineBitsTag totalLength: " << totalLength() << std::endl;
}
