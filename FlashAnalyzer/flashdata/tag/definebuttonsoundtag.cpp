#include "definebuttonsoundtag.h"

DefineButtonSoundTag::DefineButtonSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_SOUND_TAG, headerLength, dataLength)
{
}

std::string DefineButtonSoundTag::tagType() const
{
	return "DefineButtonSound";
}

std::string DefineButtonSoundTag::tagDescription() const
{
	return Tag::tagDescription();
}
