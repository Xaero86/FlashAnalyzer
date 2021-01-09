#include "definebitsjpeg3tag.h"

#include <iostream>

#include "tools.h"

DefineBitsJPEG3Tag::DefineBitsJPEG3Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ImageTag(source, DEFINE_BITS_JPEG_3_TAG, headerLength, dataLength),
 _bitmapAlphaData(nullptr),
 _bitmapAlphaDataSize(0)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    uint32_t alphaDataOffset = readUnsigned32(&_rawData[currentIndex]);
    currentIndex += sizeof(alphaDataOffset);
    
    _imageData = &_rawData[currentIndex];
    _imageDataSize = alphaDataOffset;
    currentIndex += alphaDataOffset;
    
    _bitmapAlphaData = &_rawData[currentIndex];
    _bitmapAlphaDataSize = totalLength() - currentIndex;
    
    // _bitmapAlphaData is zipper. TODO unzip
    
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

void DefineBitsJPEG3Tag::print() const
{
    std::cout << "DefineBitsJPEG3Tag valid : " << valid() << std::endl;
    std::cout << "DefineBitsJPEG3Tag code: " << code() << std::endl;
    std::cout << "DefineBitsJPEG3Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineBitsJPEG3Tag totalLength: " << totalLength() << std::endl;
}
