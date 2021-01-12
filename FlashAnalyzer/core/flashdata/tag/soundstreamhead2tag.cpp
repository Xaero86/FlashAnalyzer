#include "soundstreamhead2tag.h"

SoundStreamHead2Tag::SoundStreamHead2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_HEAD_2_TAG, headerLength, dataLength)
{
}

std::string SoundStreamHead2Tag::tagType() const
{
	return "SoundStreamHead2";
}

std::string SoundStreamHead2Tag::tagDescription() const
{
	return Tag::tagDescription();
}
