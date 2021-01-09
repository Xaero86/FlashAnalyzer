#include "jpegtablestag.h"

#include <iostream>

JPEGTablesTag::JPEGTablesTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, JPEG_TABLES_TAG, headerLength, dataLength),
 _jpegData(nullptr),
 _jpegDataSize(0)
{
    uint32_t currentIndex = headerLength;
    
    _jpegData = &_rawData[currentIndex];
    _jpegDataSize = totalLength() - currentIndex;
    
    bool erroneousJpeg = (((unsigned char) _jpegData[0] == 0xFF) && ((unsigned char) _jpegData[1] == 0xD9) &&
                          ((unsigned char) _jpegData[2] == 0xFF) && ((unsigned char) _jpegData[3] == 0xD8));

    if (erroneousJpeg)
    {
        // skip erroneous data
        _jpegData = &_jpegData[4];
        _jpegDataSize -= 4;
    }
}

void JPEGTablesTag::print() const
{
    std::cout << "JPEGTablesTag valid : " << valid() << std::endl;
    std::cout << "JPEGTablesTag code: " << code() << std::endl;
    std::cout << "JPEGTablesTag dataLength: " << dataLength() << std::endl;
    std::cout << "JPEGTablesTag totalLength: " << totalLength() << std::endl;
}
