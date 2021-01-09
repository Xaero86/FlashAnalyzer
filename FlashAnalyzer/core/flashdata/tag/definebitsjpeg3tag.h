#ifndef DEFINEBITSJPEG3TAG_H
#define DEFINEBITSJPEG3TAG_H

#include "imagetag.h"

class DefineBitsJPEG3Tag : public ImageTag
{
public:
    DefineBitsJPEG3Tag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
    
    const char* bitmapAlphaData() const {return _bitmapAlphaData;}
    uint32_t bitmapAlphaDataSize() const {return _bitmapAlphaDataSize;}

private:
    const char*  _bitmapAlphaData;
    uint32_t     _bitmapAlphaDataSize;
};

#endif // DEFINEBITSJPEG3TAG_H
