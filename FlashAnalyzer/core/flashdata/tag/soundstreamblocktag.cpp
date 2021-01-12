#include "soundstreamblocktag.h"

SoundStreamBlockTag::SoundStreamBlockTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_BLOCK_TAG, headerLength, dataLength)
{
}

std::string SoundStreamBlockTag::tagType() const
{
	return "SoundStreamBlock";
}

std::string SoundStreamBlockTag::tagDescription() const
{
	return Tag::tagDescription();
}
