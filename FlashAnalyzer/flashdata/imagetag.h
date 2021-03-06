#ifndef IMAGETAG_H
#define IMAGETAG_H

#include "definitiontag.h"
#include "extractabletag.h"

#include <QImage>

class ImageTag : public DefinitionTag, public ExtractableTag
{
public:
    enum ImageType
    {
        UNKNOWN_IMAGE,
        JPEG,
        PNG,
        GIF89a,
        BMP
    };
    
    ImageTag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
     DefinitionTag(source, code, headerLength, dataLength),
     _imageData(nullptr),
     _imageDataSize(0),
     _imageType(ImageType::UNKNOWN_IMAGE) {}
    
    const char* imageData() const {return _imageData;}
	uint32_t imageDataSize() const {return _imageDataSize;}

	virtual QImage toQImage() const = 0;
    
	std::string imageTypeStr() const
    {
        switch (_imageType)
        {
            case ImageType::JPEG:
				return std::string("JPEG");
                break;
            case ImageType::PNG:
				return std::string("PNG");
                break;
            case ImageType::GIF89a:
				return std::string("GIF");
                break;
			case ImageType::BMP:
				return std::string("BMP");
                break;
            case ImageType::UNKNOWN_IMAGE:
            default:
				return std::string("UNKNOWN");
        }
    }

    enum BitmapFormat
    {
        UNKNOWN_FORMAT = 0,
        B_8BITS = 3,
        B_15BITS = 4,
        B_24BITS = 5
    };
    
    uint8_t pixelSizeBytesSWF(BitmapFormat format) const // in swf
    {
        switch (format)
        {
            case BitmapFormat::B_8BITS:
                return 1;
                break;
            case BitmapFormat::B_15BITS:
                return 2;
                break;
            case BitmapFormat::B_24BITS:
                return 4;
                break;
            case BitmapFormat::UNKNOWN_FORMAT:
            default:
                return 0;
        }
    }
    
    uint8_t pixelSizeBytesBMP(BitmapFormat format) const // in bmp
    {
        switch (format)
        {
            case BitmapFormat::B_8BITS:
                return 1;
                break;
            case BitmapFormat::B_15BITS:
                return 2;
                break;
            case BitmapFormat::B_24BITS:
                return 3;
                break;
            case BitmapFormat::UNKNOWN_FORMAT:
            default:
                return 0;
        }
    }

	virtual std::string tagType() const override = 0;
	virtual std::string tagDescription() const override = 0;

	std::string extensionFile() const override
	{
		switch (_imageType)
		{
			case ImageType::JPEG:
				return ".jpeg";
				break;
			case ImageType::PNG:
				return ".png";
				break;
			case ImageType::GIF89a:
				return ".gif";
				break;
			case ImageType::BMP:
				return ".bmp";
				break;
			case ImageType::UNKNOWN_IMAGE:
			default:
				return "";
		}
	}
    
protected:
    const char*  _imageData;
    uint32_t     _imageDataSize;
    ImageType    _imageType;
};

#endif // IMAGETAG_H
