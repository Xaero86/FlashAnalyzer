#include "startsoundtag.h"

StartSoundTag::StartSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, START_SOUND_TAG, headerLength, dataLength)
{
}

std::string StartSoundTag::tagType() const
{
	return "StartSound";
}

std::string StartSoundTag::tagDescription() const
{
	return Tag::tagDescription();
}
