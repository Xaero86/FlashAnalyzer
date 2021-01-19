#ifndef VIDEOFRAMETAG_H
#define VIDEOFRAMETAG_H

#include "tag.h"

class VideoFrameTag : public Tag
{
public:
	VideoFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    const char* videoData() {return _videoData;}
    uint32_t videoDataSize() {return _videoDataSize;}

	std::string tagType() const override;
	std::string tagDescription() const override;
	void link(SWFFile* swfFile) override;
    
private:
    uint16_t         _streamID;
    uint16_t         _frameNum;
    const char*      _videoData;
    uint32_t         _videoDataSize;
    const char*      _videoAlphaData;
    uint32_t         _videoAlphaDataSize;
};

#endif // VIDEOFRAMETAG_H
