#include "definebitslossless2tag.h"

#include <sstream>
#include <cstring>
#include <QtZlib/zlib.h>

#include "tools.h"

DefineBitsLossless2Tag::DefineBitsLossless2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ImageTag(source, DEFINE_BITS_LOSSLESS_2_TAG, headerLength, dataLength),
 _bitmapFormat(BitmapFormat::UNKNOWN_FORMAT),
 _bitmapWidth(0),
 _bitmapHeight(0),
 _bitmapColorTableSize(0),
 _bitmapData(nullptr),
 _bitmapDataSize(0),
 _unzipData(nullptr),
 _unzipDataSize(0)
 {
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    uint8_t format = (uint8_t) _rawData[currentIndex];
    currentIndex += sizeof(format);
    _bitmapFormat = (BitmapFormat) format;
    
    _bitmapWidth = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_bitmapWidth);
    
    _bitmapHeight = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_bitmapHeight);
    
    if (_bitmapFormat == BitmapFormat::B_8BITS)
    {
        _bitmapColorTableSize = ((uint8_t) _rawData[currentIndex])+1;
         currentIndex += sizeof(uint8_t);
    }

    uint16_t paddingWidthSWF = (4 - _bitmapWidth*pixelSizeBytesSWF(_bitmapFormat) % 4) % 4;
    
    _unzipDataSize = _bitmapColorTableSize * 4 + (_bitmapWidth * pixelSizeBytesSWF(_bitmapFormat) + paddingWidthSWF) * _bitmapHeight;
    _unzipData = new char[_unzipDataSize];
    
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    
    infstream.avail_in = totalLength() - currentIndex;
    infstream.next_in = (Bytef *) &_rawData[currentIndex];
    infstream.avail_out = _unzipDataSize;
    infstream.next_out = (Bytef *) _unzipData;

    inflateInit(&infstream);
    inflate(&infstream, Z_NO_FLUSH);
    inflateEnd(&infstream);

    // header
    uint32_t bitmapDataIndex = 0;
    uint16_t paddingWidthBMP = (4 - _bitmapWidth*pixelSizeBytesBMP(_bitmapFormat) % 4) % 4;

#define HEADER_SIZE 14 + 40
    _bitmapDataSize = HEADER_SIZE + _bitmapColorTableSize * 4 + (_bitmapWidth * pixelSizeBytesBMP(_bitmapFormat) + paddingWidthBMP) * _bitmapHeight;
    _bitmapData = new char[_bitmapDataSize];
    memset(_bitmapData, 0, _bitmapDataSize);
    
    // signature 0x4D42
    writeUnsigned16(&_bitmapData[bitmapDataIndex], 0x4D42);
    bitmapDataIndex += sizeof(uint16_t);
    
    // file size
    writeUnsigned32(&_bitmapData[bitmapDataIndex], _bitmapDataSize);
    bitmapDataIndex += sizeof(uint32_t);
    
    // reserved
    bitmapDataIndex += 2*sizeof(uint16_t);
    
    // offset data
    writeUnsigned32(&_bitmapData[bitmapDataIndex], HEADER_SIZE + _bitmapColorTableSize * 4);
    bitmapDataIndex += sizeof(uint32_t);
    
    // second part header size
    writeUnsigned32(&_bitmapData[bitmapDataIndex], 40);
    bitmapDataIndex += sizeof(uint32_t);
    
    // width in pixel
    writeSigned32(&_bitmapData[bitmapDataIndex], _bitmapWidth);
    bitmapDataIndex += sizeof(int32_t);
        
    // height in pixel
    writeSigned32(&_bitmapData[bitmapDataIndex], -1 * ((int16_t) _bitmapHeight));
    bitmapDataIndex += sizeof(int32_t);
    
    // nb planes = 1
    writeUnsigned16(&_bitmapData[bitmapDataIndex], 1);
    bitmapDataIndex += sizeof(uint16_t);
    
    // nb bits per pixels
    writeUnsigned16(&_bitmapData[bitmapDataIndex], pixelSizeBytesBMP(_bitmapFormat)*8);
    bitmapDataIndex += sizeof(uint16_t);
    
    // compression
    bitmapDataIndex += sizeof(uint32_t);
    
    // data size
    bitmapDataIndex += sizeof(uint32_t);
    
    // pixels per meter x
    writeSigned32(&_bitmapData[bitmapDataIndex], 0);
    bitmapDataIndex += sizeof(int32_t);
    
    // pixels per meter y
    writeSigned32(&_bitmapData[bitmapDataIndex], 0);
    bitmapDataIndex += sizeof(int32_t);
    
    // color used
    writeUnsigned32(&_bitmapData[bitmapDataIndex], _bitmapColorTableSize);
    bitmapDataIndex += sizeof(uint32_t);
    
    // color important
    bitmapDataIndex += sizeof(uint32_t);

    _imageType = ImageType::BMP;

    if (_bitmapFormat == BitmapFormat::B_8BITS)
    {
        for (uint16_t col = 0; col < _bitmapColorTableSize; col++)
        {
            // blue
            _bitmapData[bitmapDataIndex] = _unzipData[2 + 3*col];
            bitmapDataIndex += sizeof(uint8_t);
            // green
            _bitmapData[bitmapDataIndex] = _unzipData[1 + 3*col];
            bitmapDataIndex += sizeof(uint8_t);
            // red
            _bitmapData[bitmapDataIndex] = _unzipData[0 + 3*col];
            bitmapDataIndex += sizeof(uint8_t);
            // reserved
            bitmapDataIndex += sizeof(uint8_t);
        }
        memcpy(&_bitmapData[bitmapDataIndex], &_unzipData[_bitmapColorTableSize * 4], _bitmapWidth*_bitmapHeight);
        bitmapDataIndex += sizeof(uint8_t)*_bitmapWidth*_bitmapHeight;
    }
    else if (_bitmapFormat == BitmapFormat::B_24BITS)
    {
        for (uint16_t y = 0; y < _bitmapHeight; y++)
        {
            for (uint16_t x = 0; x < _bitmapWidth; x++)
            {
                uint32_t pixelIndex = x + y*_bitmapWidth;
                // blue
                _bitmapData[bitmapDataIndex] = _unzipData[3 + 4*pixelIndex];
                bitmapDataIndex += sizeof(uint8_t);
                // green
                _bitmapData[bitmapDataIndex] = _unzipData[2 + 4*pixelIndex];
                bitmapDataIndex += sizeof(uint8_t);
                // red
                _bitmapData[bitmapDataIndex] = _unzipData[1 + 4*pixelIndex];
                bitmapDataIndex += sizeof(uint8_t);
                // _unzipData[4*pixelIndex] = alpha => void
            }
            bitmapDataIndex += sizeof(uint8_t) * paddingWidthBMP;
        }
    }
    
    _imageData = _bitmapData;
    _imageDataSize = _bitmapDataSize;
}

DefineBitsLossless2Tag::~DefineBitsLossless2Tag()
{
	if (_bitmapData != nullptr)
	{
		delete[] _bitmapData;
	}
	if (_unzipData != nullptr)
	{
		delete[] _unzipData;
	}
}

std::string DefineBitsLossless2Tag::tagType() const
{
	return "DefineBitsLossless2";
}

std::string DefineBitsLossless2Tag::tagDescription() const
{
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Color depth: " << _bitmapFormat << std::endl;
	description << "Width: " << _bitmapWidth << std::endl;
	description << "Height: " << _bitmapHeight << std::endl;

	return description.str();
}
