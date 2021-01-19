#include "definebitstag.h"

#include <sstream>

#include "tools.h"
#include "swffile.h"

DefineBitsTag::DefineBitsTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ImageTag(source, DEFINE_BITS_TAG, headerLength, dataLength),
  _tableTag(nullptr)
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

	description << DefinitionTag::tagDescription();
	description << "Type: " << imageTypeStr() << std::endl;

	return description.str();
}

void DefineBitsTag::link(SWFFile* swfFile)
{
	_tableTag = swfFile->jpegTablesTag();
}

void DefineBitsTag::extract(std::ofstream& outputFile)
{
	if ((_tableTag != nullptr) && (_tableTag->imageDataSize() > 2))
	{
		outputFile.write(_tableTag->imageData(), _tableTag->imageDataSize() - 2);
		outputFile.write(&_imageData[2], _imageDataSize - 2);
	}
	else
	{
		outputFile.write(_imageData, _imageDataSize);
	}
}

QImage DefineBitsTag::toQImage() const
{
	if ((_tableTag != nullptr) && (_tableTag->imageDataSize() > 2))
	{
		QByteArray data(_tableTag->imageData(),_tableTag->imageDataSize() - 2);
		data.append(&_imageData[2], _imageDataSize - 2);
		return QImage::fromData(data);
	}
	else
	{
		return QImage::fromData(reinterpret_cast<const unsigned char*>(_imageData), _imageDataSize);
	}
}
