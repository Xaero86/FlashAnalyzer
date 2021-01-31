#ifndef DEFINEBITSJPEG4TAG_H
#define DEFINEBITSJPEG4TAG_H

#include "imagetag.h"

class DefineBitsJPEG4Tag : public ImageTag
{
public:
    DefineBitsJPEG4Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	void extract(QDataStream &outputStream) override;
	QImage toQImage() const override;

    const char* bitmapAlphaData() const {return _bitmapAlphaData;}
    uint32_t bitmapAlphaDataSize() const {return _bitmapAlphaDataSize;}
    uint32_t deblockParam() const {return _deblockParam;}

private:
    const char*  _bitmapAlphaData;
    uint32_t     _bitmapAlphaDataSize;
    uint16_t     _deblockParam;
};

#endif // DEFINEBITSJPEG4TAG_H
