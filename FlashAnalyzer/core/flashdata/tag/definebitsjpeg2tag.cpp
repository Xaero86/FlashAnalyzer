#include "definebitsjpeg2tag.h"

#include <sstream>

#include "tools.h"

DefineBitsJPEG2Tag::DefineBitsJPEG2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ImageTag(source, DEFINE_BITS_JPEG_2_TAG, headerLength, dataLength)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _imageData = &_rawData[currentIndex];
    _imageDataSize = totalLength() - currentIndex;
    
    bool isPng = (((unsigned char) _imageData[0] == 0x89) && ((unsigned char) _imageData[1] == 0x50) &&
                  ((unsigned char) _imageData[2] == 0x4E) && ((unsigned char) _imageData[3] == 0x47) &&
                  ((unsigned char) _imageData[4] == 0x0D) && ((unsigned char) _imageData[5] == 0x0A) &&
                  ((unsigned char) _imageData[6] == 0x1A) && ((unsigned char) _imageData[7] == 0x0A));
    
    if (isPng)
    {
        _imageType = ImageType::PNG;
    }
    else
    {
        bool isGif89a = (((unsigned char) _imageData[0] == 0x47) && ((unsigned char) _imageData[1] == 0x49) &&
                         ((unsigned char) _imageData[2] == 0x46) && ((unsigned char) _imageData[3] == 0x38) &&
                         ((unsigned char) _imageData[4] == 0x39) && ((unsigned char) _imageData[5] == 0x61));
        
        if (isGif89a)
        {
            _imageType = ImageType::GIF89a;
        }
        else
        {
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
    }
}

std::string DefineBitsJPEG2Tag::tagType() const
{
	return "DefineBitsJPEG2";
}

std::string DefineBitsJPEG2Tag::tagDescription() const
{
	std::stringstream description;

	description << DefinitionTag::tagDescription();
	description << "Type: " << imageTypeStr() << std::endl;

	return description.str();
}

void DefineBitsJPEG2Tag::extract(QDataStream &outputStream)
{
	outputStream.writeRawData(_imageData, _imageDataSize);
}

QImage DefineBitsJPEG2Tag::toQImage() const
{
	return QImage::fromData(reinterpret_cast<const unsigned char*>(_imageData), _imageDataSize);
}
