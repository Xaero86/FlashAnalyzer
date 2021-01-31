#ifndef DEFINEBUTTONSOUNDTAG_H
#define DEFINEBUTTONSOUNDTAG_H

#include "tag.h"

class DefineButtonSoundTag : public Tag
{
public:
    DefineButtonSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEBUTTONSOUNDTAG_H
