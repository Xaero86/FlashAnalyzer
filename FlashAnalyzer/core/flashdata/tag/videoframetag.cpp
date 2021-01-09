#include "videoframetag.h"

#include <iostream>

#include "tools.h"
#include "swffile.h"
#include "definevideostreamtag.h"

VideoFrameTag::VideoFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength, SWFFile* swfFile) :
 Tag(source, VIDEO_FRAME_TAG, headerLength, dataLength),
 _streamID(0),
 _frameNum(0),
 _videoData(nullptr),
 _videoDataSize(0),
 _videoAlphaData(nullptr),
 _videoAlphaDataSize(0)
{
    uint32_t currentIndex = headerLength;
    _streamID = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_streamID);
    
    _frameNum = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_frameNum);

    if (swfFile == nullptr)
    {
        _valid = false;
        return;
    }
    DefinitionTag* videoStreamTemp = swfFile->getDefinitionTag(_streamID);
    if (videoStreamTemp == nullptr)
    {
        _valid = false;
        return;
    }
    DefineVideoStreamTag* videoStream = dynamic_cast<DefineVideoStreamTag*>(videoStreamTemp);
    if (!videoStream)
    {
        _valid = false;
        return;
    }
    
    videoStream->setFrame(this, _frameNum);
    
    switch (videoStream->codecId())
    {
        case DefineVideoStreamTag::VP6:
            _videoData = &_rawData[currentIndex];
            _videoDataSize = totalLength() - currentIndex;
            break;
        case DefineVideoStreamTag::VP6_ALPHA:
            // TODO not endianess compatible
            _videoDataSize = readUnsigned32(&_rawData[currentIndex]) >> 8;
            currentIndex += sizeof(uint16_t) * 3; // UI24 !!
            _videoData = &_rawData[currentIndex];
            currentIndex += _videoDataSize;
            _videoAlphaData = &_rawData[currentIndex];
            _videoAlphaDataSize = totalLength() - currentIndex;
            break;
        default:
            //TODO
            return;
    }
}

void VideoFrameTag::print() const
{
    std::cout << "VideoFrameTag valid : " << valid() << std::endl;
    std::cout << "VideoFrameTag code: " << code() << std::endl;
    std::cout << "VideoFrameTag dataLength: " << dataLength() << std::endl;
    std::cout << "VideoFrameTag totalLength: " << totalLength() << std::endl;
}
