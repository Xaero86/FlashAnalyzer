#include "soundstreamheadtag.h"

#include <iostream>

SoundStreamHeadTag::SoundStreamHeadTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_HEAD_TAG, headerLength, dataLength)
{
}

void SoundStreamHeadTag::print() const
{
    std::cout << "SoundStreamHeadTag valid : " << valid() << std::endl;
    std::cout << "SoundStreamHeadTag code: " << code() << std::endl;
    std::cout << "SoundStreamHeadTag dataLength: " << dataLength() << std::endl;
    std::cout << "SoundStreamHeadTag totalLength: " << totalLength() << std::endl;
}
