#include "definebuttonsoundtag.h"

#include <iostream>

DefineButtonSoundTag::DefineButtonSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BUTTON_SOUND_TAG, headerLength, dataLength)
{
}

void DefineButtonSoundTag::print() const
{
    std::cout << "DefineButtonSoundTag valid : " << valid() << std::endl;
    std::cout << "DefineButtonSoundTag code: " << code() << std::endl;
    std::cout << "DefineButtonSoundTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineButtonSoundTag totalLength: " << totalLength() << std::endl;
}
