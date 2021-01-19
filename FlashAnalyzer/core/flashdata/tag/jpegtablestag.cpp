#include "jpegtablestag.h"

JPEGTablesTag::JPEGTablesTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, JPEG_TABLES_TAG, headerLength, dataLength),
 _jpegData(nullptr),
 _jpegDataSize(0)
{
    uint32_t currentIndex = headerLength;
    
    _jpegData = &_rawData[currentIndex];
    _jpegDataSize = totalLength() - currentIndex;

	if (_jpegDataSize < 4)
	{
		return;
	}
    
    bool erroneousJpeg = (((unsigned char) _jpegData[0] == 0xFF) && ((unsigned char) _jpegData[1] == 0xD9) &&
                          ((unsigned char) _jpegData[2] == 0xFF) && ((unsigned char) _jpegData[3] == 0xD8));

    if (erroneousJpeg)
    {
        // skip erroneous data
        _jpegData = &_jpegData[4];
        _jpegDataSize -= 4;
    }
}

std::string JPEGTablesTag::tagType() const
{
	return "JPEGTables";
}

std::string JPEGTablesTag::tagDescription() const
{
	return Tag::tagDescription();
}
