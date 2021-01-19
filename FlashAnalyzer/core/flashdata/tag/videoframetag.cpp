#include "videoframetag.h"

#include "tools.h"
#include "swffile.h"
#include "definevideostreamtag.h"

VideoFrameTag::VideoFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, VIDEO_FRAME_TAG, headerLength, dataLength),
 _streamID(0),
 _frameNum(0),
 _videoData(nullptr),
 _videoDataSize(0)
{
    uint32_t currentIndex = headerLength;
    _streamID = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_streamID);
    
    _frameNum = readUnsigned16(&_rawData[currentIndex]);
	currentIndex += sizeof(_frameNum);

	_videoData = &_rawData[currentIndex];
	_videoDataSize = totalLength() - currentIndex;
}

std::string VideoFrameTag::tagType() const
{
	return "VideoFrame";
}

std::string VideoFrameTag::tagDescription() const
{
	return Tag::tagDescription();
}

void VideoFrameTag::link(SWFFile* swfFile)
{
	DefineVideoStreamTag* streamTag = dynamic_cast<DefineVideoStreamTag*>(swfFile->getDefinitionTag(_streamID));

	if (streamTag != nullptr)
	{
		streamTag->setFrame(this, _frameNum);
	}
}
