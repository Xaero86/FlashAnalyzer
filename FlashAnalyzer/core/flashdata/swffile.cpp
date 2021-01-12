#include "swffile.h"

#include <iostream>
#include <fstream>
#include <errno.h>
#include <string.h>
#include <sstream>
#include <QtZlib/zlib.h>

#include "tools.h"

SWFFile::SWFFile(std::string fileName) :
 _fileName(fileName),
 _valid(true),
 _compressType(UNKNOWN_COMPRESS_TYPE),
 _version(0),
 _fileLength(0),
 _frameSize(),
 _frameRate(0),
 _frameCount(0),
 _dataSize(0),
 _data(nullptr),
 _tags(),
 _fileAttributesTag(nullptr),
 _jpegTablesTag(nullptr)
{
    // Open file
    std::ifstream flashFile;
	flashFile.open(_fileName, std::fstream::binary | std::fstream::ate);
	if (!flashFile)
    {
        _valid = false;
		std::cerr << "Cannot open " << _fileName << ": " << strerror(errno) << std::endl;
        return;
    }
    
    // File length
    std::streamsize fileLength = flashFile.tellg();
    flashFile.seekg(0, std::ios::beg);
    
    // First part header
#define HEADER_SIZE 8
    char data[HEADER_SIZE];

    flashFile.read(data, HEADER_SIZE);
    if (!flashFile)
    {
        _valid = false;
        std::cerr << "Error reading header" << std::endl;
        return;
    }

    // Compression type
    switch (data[0])
    {
        case 'F':
            _compressType = NONE;
            break;
        case 'C':
            _compressType = ZLIB;
            break;
        case 'Z':
            _compressType = LZMA;
            break;
        default:
            _valid = false;
            std::cerr << "Unknown compression type: " << (unsigned int) data[0] << std::endl;
            return;
    }
    
    // Constante
    if (data[1] != 'W' || data[2] != 'S')
    {
        _valid = false;
        std::cerr << "Invalid header" << std::endl;
        return;
    }
    
    // Version
    _version = (unsigned char) data[3];

    // Data size
    // If uncompressed, size of whole file
    // If compressed, size of the uncompressed data
    _fileLength = readUnsigned32(&data[4]);
    
    if (_compressType == NONE)
    {
        if (_fileLength != fileLength)
        {
            std::cerr << "Warning: Incorrect file size" << std::endl;
        }
        
        _dataSize = _fileLength - HEADER_SIZE;
        _data = new char[_dataSize];
        flashFile.read(_data, _dataSize);
        if (!flashFile)
        {
            _valid = false;
            std::cerr << "Error reading data" << std::endl;
            return;
        }
    }
    else
    {
        uint32_t compressedDataSize = fileLength - HEADER_SIZE;
        char* compressedData = new char[compressedDataSize];
        flashFile.read(compressedData, compressedDataSize);
        if (!flashFile)
        {
            _valid = false;
            std::cerr << "Error reading data" << std::endl;
            return;
        }
        
        _dataSize = _fileLength;
        _data = new char[_dataSize];
        
        if (_compressType == ZLIB)
        {
            z_stream infstream;
            infstream.zalloc = Z_NULL;
            infstream.zfree = Z_NULL;
            infstream.opaque = Z_NULL;
            
            infstream.avail_in = compressedDataSize;
            infstream.next_in = (Bytef *) compressedData;
            infstream.avail_out = _dataSize;
            infstream.next_out = (Bytef *) _data;
            
            inflateInit(&infstream);
            inflate(&infstream, Z_NO_FLUSH);
            inflateEnd(&infstream);
        }
        else // LZMA
        {
            // unzip compressedData => _data TODO
            _valid = false;
            std::cerr << "LZMA compression not yet implemented" << std::endl;
            return;
        }

    }

    // Frame size
    _frameSize.create(_data, _dataSize);
    
    uint32_t currentReadIndex = _frameSize.dataSize();
    
    // Frame rate
    // Frame delay in 8.8 fixed number of frames per second (and decimal is ignored)
    _frameRate = readUnsigned16(&_data[currentReadIndex]) >> 8;
    currentReadIndex += sizeof(_frameRate);
    
    // Frame count
    _frameCount = readUnsigned16(&_data[currentReadIndex]);
    currentReadIndex += sizeof(_frameCount);

	Tag* newTag = nullptr;

    while (_dataSize > currentReadIndex)
    {
		newTag = Tag::AddNextTag(&_data[currentReadIndex], _dataSize-currentReadIndex, _tags);
		if ((newTag != nullptr) && (newTag->totalLength() > 0) && newTag->valid())
		{
			currentReadIndex += newTag->totalLength();
            
			if (newTag->code() == FILE_ATTRIBUTES_TAG)
            {
                if (_tags.size() != 1)
                {
                    std::cerr << "Warning: file attibutes tag is not locate at the beginning" << std::endl;
                }
				_fileAttributesTag = (FileAttributesTag*) &newTag;
            }
			else if (newTag->code() == JPEG_TABLES_TAG)
            {
                if (_jpegTablesTag != nullptr)
                {
                    std::cerr << "Warning: only one JPEG table tag is allowed" << std::endl;
                }
				_jpegTablesTag = (JPEGTablesTag*) &newTag;
            }
        }
        else
        {
            _valid = false;
            std::cerr << "Fail to create tag" << std::endl;
            break;
        }
    }
}

SWFFile::~SWFFile()
{
    if (_data != nullptr)
    {
        delete[] _data;
    }
}

std::string SWFFile::toString() const
{
    std::stringstream result;
    if (_valid)
    {
        result << "SWF file: " << _fileName << std::endl;
        result << "Compression: " << ((_compressType==NONE)?"uncompressed":((_compressType==ZLIB)?"zlib":"LZMA")) << std::endl;
        result << "Version: " << (unsigned int) _version << std::endl;
    }
    else
    {
        result << "SWF file: " << _fileName << " (invalid)";
    }
    return result.str();
}

/*DefinitionTag* SWFFile::getDefinitionTag(uint16_t charactedId) const
{
    DefinitionTag* result = nullptr;
    for (Tag::const_iterator itTag = cbegin(); itTag != cend(); ++itTag)
    {
        result = dynamic_cast<DefinitionTag*>(*itTag);
        if (result && (result->uid() == charactedId))
        {
            return result;
        }
    }
    return nullptr;
}*/
