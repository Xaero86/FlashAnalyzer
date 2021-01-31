#include "videoframetag.h"

#include "tools.h"
#include "swffile.h"
#include "definevideostreamtag.h"

#include <sstream>

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
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Stream ID: " << _streamID << std::endl;
	description << "Frame number: " << _frameNum << std::endl;
	description << "Video data size: " << _videoDataSize << std::endl;

	return description.str();
}

void VideoFrameTag::link(SWFFile* swfFile)
{
	DefineVideoStreamTag* streamTag = dynamic_cast<DefineVideoStreamTag*>(swfFile->getDefinitionTag(_streamID));

	if (streamTag != nullptr)
	{
		streamTag->setFrame(this, _frameNum);
	}
}

uint32_t VideoFrameTag::toFlv(QDataStream& flvStream, CodecID codecId, unsigned int fps, uint16_t width, uint16_t height) const
{
	uint32_t totalWritten = 0;
	// Type (8=audio, 9=video)
	flvStream << (uchar) 9;
	totalWritten += sizeof (uchar);
	// Data size
	uint32_t totalDataSize = _videoDataSize+1;
	if ((codecId == CodecID::VP6) || (codecId == CodecID::VP6_ALPHA))
	{
		totalDataSize++;
	}
	flvStream << (uchar) ((totalDataSize & 0xFF0000) >> 16);
	flvStream << (uchar) ((totalDataSize & 0xFF00) >> 8);
	flvStream << (uchar) (totalDataSize & 0xFF);
	totalWritten += 3 * sizeof (uchar);
	// Timestamp (ms)
	int32_t timestamp = _frameNum * fps;
	flvStream << (uchar) ((timestamp & 0xFF0000) >> 16);
	flvStream << (uchar) ((timestamp & 0xFF00) >> 8);
	flvStream << (uchar) (timestamp & 0xFF);
	totalWritten += 3 * sizeof (uchar);
	// Timestamp extended
	flvStream << (uchar) ((timestamp & 0xFF000000) >> 24);
	totalWritten += sizeof (uchar);
	// StreamID (always 0)
	flvStream << (uchar) 0;
	flvStream << (uchar) 0;
	flvStream << (uchar) 0;
	totalWritten += 3 * sizeof (uchar);

	// Data
	// Frame type (0 : 4bits) + codecId (4bits)
	flvStream << (uchar) codecId;
	totalWritten += sizeof (uchar);
	// Video data
	if ((codecId == CodecID::VP6) || (codecId == CodecID::VP6_ALPHA))
	{
		// Adjustment
		uint16_t vp6HAdj = (16-width%16)%16;
		uint16_t vp6VAdj = (16-height%16)%16;
		uchar adjustment = ((vp6HAdj & 0xf) << 4) + (vp6VAdj & 0xf);
		flvStream << (uchar) adjustment;
		totalWritten += sizeof (uchar);
	}
	flvStream.writeRawData(_videoData, _videoDataSize);
	totalWritten += _videoDataSize;

	return totalWritten;
}
