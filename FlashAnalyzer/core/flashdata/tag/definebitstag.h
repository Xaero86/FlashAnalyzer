#ifndef DEFINEBITSTAG_H
#define DEFINEBITSTAG_H

#include "imagetag.h"

class DefineBitsTag : public ImageTag
{
public:
    DefineBitsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINEBITSTAG_H
