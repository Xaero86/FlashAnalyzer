#ifndef DEFINEBITSLOSSLESSTAG_H
#define DEFINEBITSLOSSLESSTAG_H

#include "imagetag.h"

class DefineBitsLosslessTag : public ImageTag
{
public:
    DefineBitsLosslessTag(const char* source, uint32_t headerLength, uint32_t dataLength);
	virtual ~DefineBitsLosslessTag();

	std::string tagType() const;
	std::string tagDescription() const;
    
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
