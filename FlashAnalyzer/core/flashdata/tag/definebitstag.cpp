#include "definebitstag.h"

#include <sstream>

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

std::string DefineBitsTag::tagType() const
{
	return "DefineBits";
}

std::string DefineBitsTag::tagDescription() const
{
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Type: " << imageTypeExtension() << std::endl;

	return description.str();
}
