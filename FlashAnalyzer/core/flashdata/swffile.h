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
    
    Tag::iterator begin() { return _tags.begin(); }
    Tag::iterator end() { return _tags.end(); }
    Tag::const_iterator begin() const { return _tags.begin(); }
    Tag::const_iterator end() const { return _tags.end(); }
    Tag::const_iterator cbegin() const { return _tags.cbegin(); }
    Tag::const_iterator cend() const { return _tags.cend(); }
    
    std::string toString() const;
    
    FileAttributesTag* fileAttributesTag() const {return _fileAttributesTag;}
    JPEGTablesTag* jpegTablesTag() const {return _jpegTablesTag;}
    DefinitionTag* getDefinitionTag(uint16_t charactedId) const;
    
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
