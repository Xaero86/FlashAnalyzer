#include "startsoundtag.h"

#include <iostream>

StartSoundTag::StartSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, START_SOUND_TAG, headerLength, dataLength)
{
}

void StartSoundTag::print() const
{
    std::cout << "StartSoundTag valid : " << valid() << std::endl;
    std::cout << "StartSoundTag code: " << code() << std::endl;
    std::cout << "StartSoundTag dataLength: " << dataLength() << std::endl;
    std::cout << "StartSoundTag totalLength: " << totalLength() << std::endl;
}
