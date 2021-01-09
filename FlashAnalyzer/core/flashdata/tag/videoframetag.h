#ifndef VIDEOFRAMETAG_H
#define VIDEOFRAMETAG_H

#include "tag.h"

class VideoFrameTag : public Tag
{
public:
    VideoFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength, SWFFile* swfFile);
    
    const char* videoData() {return _videoData;}
    uint32_t videoDataSize() {return _videoDataSize;}
    
    void print() const;
    
private:
    uint16_t         _streamID;
    uint16_t         _frameNum;
    const char*      _videoData;
    uint32_t         _videoDataSize;
    const char*      _videoAlphaData;
    uint32_t         _videoAlphaDataSize;
};

#endif // VIDEOFRAMETAG_H
