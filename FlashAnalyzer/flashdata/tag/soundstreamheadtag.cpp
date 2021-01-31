#include "soundstreamheadtag.h"

SoundStreamHeadTag::SoundStreamHeadTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_HEAD_TAG, headerLength, dataLength)
{
}

std::string SoundStreamHeadTag::tagType() const
{
	return "SoundStreamHead";
}

std::string SoundStreamHeadTag::tagDescription() const
{
	return Tag::tagDescription();
}
