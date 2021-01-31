#ifndef DEFINEBITSJPEG3TAG_H
#define DEFINEBITSJPEG3TAG_H

#include "imagetag.h"

class DefineBitsJPEG3Tag : public ImageTag
{
public:
    DefineBitsJPEG3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	void extract(QDataStream& outputStream) override;
	QImage toQImage() const override;
    
    const char* bitmapAlphaData() const {return _bitmapAlphaData;}
    uint32_t bitmapAlphaDataSize() const {return _bitmapAlphaDataSize;}

private:
    const char*  _bitmapAlphaData;
    uint32_t     _bitmapAlphaDataSize;
};

#endif // DEFINEBITSJPEG3TAG_H
