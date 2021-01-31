#include "startsound2tag.h"

StartSound2Tag::StartSound2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, START_SOUND_2_TAG, headerLength, dataLength)
{
}

std::string StartSound2Tag::tagType() const
{
	return "StartSound2";
}

std::string StartSound2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
