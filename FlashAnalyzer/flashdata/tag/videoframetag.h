#ifndef VIDEOFRAMETAG_H
#define VIDEOFRAMETAG_H

#include "tag.h"
#include "datatypes.h"

#include <QDataStream>

class VideoFrameTag : public Tag
{
public:
	VideoFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    const char* videoData() {return _videoData;}
    uint32_t videoDataSize() {return _videoDataSize;}

	std::string tagType() const override;
	std::string tagDescription() const override;
	void link(SWFFile* swfFile) override;

	uint32_t toFlv(QDataStream& flvStream, CodecID codecId, unsigned int fps, uint16_t width, uint16_t height) const;

private:
    uint16_t         _streamID;
    uint16_t         _frameNum;
    const char*      _videoData;
    uint32_t         _videoDataSize;
    const char*      _videoAlphaData;
    uint32_t         _videoAlphaDataSize;
};

#endif // VIDEOFRAMETAG_H
