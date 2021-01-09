#include "soundstreamblocktag.h"

#include <iostream>

SoundStreamBlockTag::SoundStreamBlockTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_BLOCK_TAG, headerLength, dataLength)
{
}

void SoundStreamBlockTag::print() const
{
    std::cout << "SoundStreamBlockTag valid : " << valid() << std::endl;
    std::cout << "SoundStreamBlockTag code: " << code() << std::endl;
    std::cout << "SoundStreamBlockTag dataLength: " << dataLength() << std::endl;
    std::cout << "SoundStreamBlockTag totalLength: " << totalLength() << std::endl;
}
