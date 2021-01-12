#ifndef SWFFILE_H
#define SWFFILE_H

#include <string>

#include "datatypes.h"
#include "tag.h"
#include "fileattributestag.h"
#include "jpegtablestag.h"
#include "definitiontag.h"

class SWFFile
{
public:
	SWFFile(std::string fileName);
    virtual ~SWFFile();
    
    inline bool valid() const {return _valid;}

	Tag::tags_t& tags() {return _tags;}
    
    std::string toString() const;
    
	FileAttributesTag* fileAttributesTag() const {return _fileAttributesTag;}
	JPEGTablesTag* jpegTablesTag() const {return _jpegTablesTag;}

	const char* data() const {return _data;}
	uint32_t dataSize() const {return _dataSize;}
    
private:
    enum CompressType
    {
        NONE,
        ZLIB,
        LZMA,
		UNKNOWN_COMPRESS_TYPE
    };
    
    std::string         _fileName;
    bool                _valid;
    
    CompressType        _compressType;
    unsigned char       _version;
    uint32_t            _fileLength; // Read from header
    RectangleRecord     _frameSize;
    uint16_t            _frameRate;
    uint16_t            _frameCount;
    
    uint32_t            _dataSize;
    char*               _data;
    Tag::tags_t         _tags;
	FileAttributesTag*  _fileAttributesTag;
	JPEGTablesTag*      _jpegTablesTag;
};

#endif // SWFFILE_H
