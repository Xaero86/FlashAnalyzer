#ifndef DEFINEBITSJPEG2TAG_H
#define DEFINEBITSJPEG2TAG_H

#include "imagetag.h"

class DefineBitsJPEG2Tag : public ImageTag
{
public:
    DefineBitsJPEG2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	void extract(QDataStream& outputStream) override;
	QImage toQImage() const override;
};

#endif // DEFINEBITSJPEG2TAG_H
