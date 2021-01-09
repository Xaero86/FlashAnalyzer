#include "soundstreamhead2tag.h"

#include <iostream>

SoundStreamHead2Tag::SoundStreamHead2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, SOUND_STREAM_HEAD_2_TAG, headerLength, dataLength)
{
}

void SoundStreamHead2Tag::print() const
{
    std::cout << "SoundStreamHead2Tag valid : " << valid() << std::endl;
    std::cout << "SoundStreamHead2Tag code: " << code() << std::endl;
    std::cout << "SoundStreamHead2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "SoundStreamHead2Tag totalLength: " << totalLength() << std::endl;
}
