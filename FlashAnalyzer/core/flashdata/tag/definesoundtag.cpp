#include "definesoundtag.h"

#include <iostream>

DefineSoundTag::DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SOUND_TAG, headerLength, dataLength)
{
}

void DefineSoundTag::print() const
{
    std::cout << "DefineSoundTag valid : " << valid() << std::endl;
    std::cout << "DefineSoundTag code: " << code() << std::endl;
    std::cout << "DefineSoundTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineSoundTag totalLength: " << totalLength() << std::endl;
}
