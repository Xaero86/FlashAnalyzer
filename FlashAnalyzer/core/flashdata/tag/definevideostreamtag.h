#ifndef DEFINEVIDEOSTREAMTAG_H
#define DEFINEVIDEOSTREAMTAG_H

#include "definitiontag.h"
#include "videoframetag.h"

class DefineVideoStreamTag : public DefinitionTag
{
public:
    enum VideoFlags
    {
        VIDEOPACKET = 0,
        OFF = 1,
        LEVEL_1 = 2,
        LEVEL_2 = 3,
        LEVEL_3 = 4,
        LEVEL_4 = 5,
        UNKNOWN_FLAG
    };
    
    enum CodecID
    {
        SORENSON_H_263 = 2,
        SCREEN_VIDEO = 3,
        VP6 = 4,
        VP6_ALPHA = 5,
        UNKNOWN_CODEC
    };
    
    const char* videoTypeExtension() const
    {
        switch (_codecId)
        {
            case CodecID::SORENSON_H_263:
                return ".h263";
                break;
            case CodecID::SCREEN_VIDEO:
                return "";
                break;
            case CodecID::VP6:
            case CodecID::VP6_ALPHA:
                return ".vp6";
                break;
            case CodecID::UNKNOWN_CODEC:
            default:
                return "";
        }
    }
    
    DefineVideoStreamTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    uint16_t numFrames() const {return _numFrames;}
    uint16_t width() const {return _width;}
    uint16_t height() const {return _height;}
    CodecID  codecId() const {return _codecId;}
    
    void setFrame(VideoFrameTag* frame, uint16_t index);
    VideoFrameTag* getFrame(uint16_t index) const;
    
    void print() const;
    
private:
    uint16_t        _numFrames;
    uint16_t        _width;
    uint16_t        _height;
    VideoFlags      _flags;
    bool            _smoothing;
    CodecID         _codecId;
    VideoFrameTag** _frames;
};

#endif // DEFINEVIDEOSTREAMTAG_H
