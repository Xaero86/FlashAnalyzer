#ifndef DEFINEBITSJPEG2TAG_H
#define DEFINEBITSJPEG2TAG_H

#include "imagetag.h"

class DefineBitsJPEG2Tag : public ImageTag
{
public:
    DefineBitsJPEG2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINEBITSJPEG2TAG_H
