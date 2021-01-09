#include "showframetag.h"

#include <iostream>

ShowFrameTag::ShowFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SHOW_FRAME_TAG, headerLength, dataLength)
{
}

void ShowFrameTag::print() const
{
    std::cout << "ShowFrameTag valid : " << valid() << std::endl;
    std::cout << "ShowFrameTag code: " << code() << std::endl;
    std::cout << "ShowFrameTag dataLength: " << dataLength() << std::endl;
    std::cout << "ShowFrameTag totalLength: " << totalLength() << std::endl;
}
