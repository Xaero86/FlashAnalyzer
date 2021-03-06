#ifndef DEFINEVIDEOSTREAMTAG_H
#define DEFINEVIDEOSTREAMTAG_H

#include "definitiontag.h"
#include "datatypes.h"
#include "videoframetag.h"
#include "extractabletag.h"

#include <QByteArray>
#include <QDir>
#include <QUrl>

class DefineVideoStreamTag : public DefinitionTag, public ExtractableTag
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

	DefineVideoStreamTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    uint16_t numFrames() const {return _numFrames;}
    uint16_t width() const {return _width;}
    uint16_t height() const {return _height;}
    CodecID  codecId() const {return _codecId;}
    
    void setFrame(VideoFrameTag* frame, uint16_t index);
    VideoFrameTag* getFrame(uint16_t index) const;

	std::string tagType() const override;
	std::string tagDescription() const override;

	std::string extensionFile() const override;
	void extract(QDataStream &outputStream) override;
	void createVideoFile(QDir& folder, QString &fileName);
	const QUrl &getVideoFile() const {return _urlFile;}
    
private:
    uint16_t        _numFrames;
    uint16_t        _width;
    uint16_t        _height;
    VideoFlags      _flags;
    bool            _smoothing;
    CodecID         _codecId;
    VideoFrameTag** _frames;

	QByteArray      _flvContent;
	QFile*          _file;
	QUrl            _urlFile;

	void toFlv();
};

#endif // DEFINEVIDEOSTREAMTAG_H
