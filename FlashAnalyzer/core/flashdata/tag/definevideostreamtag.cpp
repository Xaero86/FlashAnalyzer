#include "definevideostreamtag.h"

#include <sstream>
#include <cstring>

#include <QDataStream>

#include "tools.h"

DefineVideoStreamTag::DefineVideoStreamTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_VIDEO_STREAM_TAG, headerLength, dataLength),
 _numFrames(0),
 _width(0),
 _height(0),
 _flags(UNKNOWN_FLAG),
 _smoothing(false),
 _codecId(UNKNOWN_CODEC),
 _frames(nullptr),
 _flvContent()
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

std::string DefineVideoStreamTag::tagType() const
{
	return "DefineVideoStream";
}

std::string DefineVideoStreamTag::tagDescription() const
{
	std::stringstream description;

	description << DefinitionTag::tagDescription();
	description << "Number of frames: " << _numFrames << std::endl;
	description << "Width: " << _width << std::endl;
	description << "Height: " << _height << std::endl;
	switch (_codecId) {
	case SORENSON_H_263:
		description << "Codec: SORENSON_H_263" << std::endl;
		break;
	case SCREEN_VIDEO:
		description << "Codec: SCREEN_VIDEO" << std::endl;
		break;
	case VP6:
		description << "Codec: VP6" << std::endl;
		break;
	case VP6_ALPHA:
		description << "Codec: VP6_ALPHA" << std::endl;
		break;
	case UNKNOWN_CODEC:
	default:
		description << "Codec: UNKNOWN: " << _codecId << std::endl;
		break;
	}

	return description.str();
}

std::string DefineVideoStreamTag::extensionFile() const
{
	return ".flv";
}

void DefineVideoStreamTag::extract(std::ofstream& outputFile)
{
	toFlv();
	outputFile.write(_flvContent.data(), _flvContent.count());
}

QByteArray DefineVideoStreamTag::getFlv()
{
	toFlv();
	return _flvContent;
}

void DefineVideoStreamTag::toFlv()
{
	if (!_flvContent.isEmpty())
	{
		return;
	}
	QDataStream flvStream(&_flvContent, QIODevice::WriteOnly);
	flvStream.setByteOrder(QDataStream::BigEndian);
	// Header
	flvStream << (uchar) 'F';
	flvStream << (uchar) 'L';
	flvStream << (uchar) 'V';
	// Version
	flvStream << (uchar) 0x01;
	// Flag (video=1, audio=4)
	flvStream << (uchar) 0x01;
	// Header size
	flvStream << (uint32_t) 9;

	// Previous tag size (first is 0)
	flvStream << (uint32_t) 0;

	for (int frameIndex = 0; frameIndex < _numFrames; frameIndex++)
	{
		// Previous tag size
		VideoFrameTag* currentFrame = _frames[frameIndex];
		if (currentFrame != nullptr)
		{
			// 40 fps
			uint32_t tagSize = currentFrame->toFlv(flvStream, _codecId, 40, _width, _height);
			flvStream << (uint32_t) tagSize;
		}
	}
}
