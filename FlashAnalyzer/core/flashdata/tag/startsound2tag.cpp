#include "startsound2tag.h"

#include <iostream>

StartSound2Tag::StartSound2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, START_SOUND_2_TAG, headerLength, dataLength)
{
}

void StartSound2Tag::print() const
{
    std::cout << "StartSound2Tag valid : " << valid() << std::endl;
    std::cout << "StartSound2Tag code: " << code() << std::endl;
    std::cout << "StartSound2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "StartSound2Tag totalLength: " << totalLength() << std::endl;
}
