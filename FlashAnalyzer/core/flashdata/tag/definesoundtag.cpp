#include "definesoundtag.h"

DefineSoundTag::DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SOUND_TAG, headerLength, dataLength)
{
}

std::string DefineSoundTag::tagType() const
{
	return "DefineSound";
}

std::string DefineSoundTag::tagDescription() const
{
	return Tag::tagDescription();
}
