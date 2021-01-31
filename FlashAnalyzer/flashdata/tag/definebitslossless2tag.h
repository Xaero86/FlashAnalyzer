#ifndef DEFINEBITSLOSSLESS2TAG_H
#define DEFINEBITSLOSSLESS2TAG_H

#include "imagetag.h"

class DefineBitsLossless2Tag : public ImageTag
{
public:
    DefineBitsLossless2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
	virtual ~DefineBitsLossless2Tag();

	std::string tagType() const override;
	std::string tagDescription() const override;

	void extract(QDataStream &outputStream) override;
	QImage toQImage() const override;
    
private:
    BitmapFormat _bitmapFormat;
    uint16_t     _bitmapWidth;
    uint16_t     _bitmapHeight;
    uint16_t     _bitmapColorTableSize;
    char*        _bitmapData;
    uint32_t     _bitmapDataSize;
    char*        _unzipData;
    uint32_t     _unzipDataSize;
};

#endif // DEFINEBITSLOSSLESS2TAG_H
