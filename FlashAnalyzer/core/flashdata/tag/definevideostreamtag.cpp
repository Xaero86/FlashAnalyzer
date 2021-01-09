#include "definevideostreamtag.h"

#include <iostream>
#include <cstring>

#include "tools.h"

DefineVideoStreamTag::DefineVideoStreamTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_VIDEO_STREAM_TAG, headerLength, dataLength),
 _numFrames(0),
 _width(0),
 _height(0),
 _flags(UNKNOWN_FLAG),
 _smoothing(false),
 _codecId(UNKNOWN_CODEC),
 _frames(nullptr)
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _numFrames = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_numFrames);
    
    _width = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_width);
    
    _height = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_height);
    
    unsigned char flags = (unsigned char) _rawData[currentIndex];
    currentIndex += sizeof(unsigned char);
    
    _flags = (VideoFlags) ((flags & 0x0E) >> 1);
    _smoothing = (flags & 0x01);
    
    _codecId = (CodecID) ((unsigned char) _rawData[currentIndex]);
    currentIndex += sizeof(_codecId);
    
    _frames = new VideoFrameTag*[_numFrames];
    std::fill_n(_frames, _numFrames, nullptr);
}

void DefineVideoStreamTag::setFrame(VideoFrameTag* frame, uint16_t index)
{
    if (index < _numFrames)
    {
        _frames[index] = frame;
    }
}

VideoFrameTag* DefineVideoStreamTag::getFrame(uint16_t index) const
{
    if (index < _numFrames)
    {
        return _frames[index];
    }
    else
    {
        return nullptr;
    }
}

void DefineVideoStreamTag::print() const
{
    std::cout << "DefineVideoStreamTag valid : " << valid() << std::endl;
    std::cout << "DefineVideoStreamTag code: " << code() << std::endl;
    std::cout << "DefineVideoStreamTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineVideoStreamTag totalLength: " << totalLength() << std::endl;
}
