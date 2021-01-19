#ifndef DEFINEBITSLOSSLESSTAG_H
#define DEFINEBITSLOSSLESSTAG_H

#include "imagetag.h"

class DefineBitsLosslessTag : public ImageTag
{
public:
    DefineBitsLosslessTag(const char* source, uint32_t headerLength, uint32_t dataLength);
	virtual ~DefineBitsLosslessTag();

	std::string tagType() const override;
	std::string tagDescription() const override;

	void extract(std::ofstream& outputFile) override;
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

#endif // DEFINEBITSLOSSLESSTAG_H
