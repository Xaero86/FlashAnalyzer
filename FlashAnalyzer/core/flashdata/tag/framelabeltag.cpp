#include "framelabeltag.h"

#include <iostream>

FrameLabelTag::FrameLabelTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, FRAME_LABEL_TAG, headerLength, dataLength)
{
}

void FrameLabelTag::print() const
{
    std::cout << "FrameLabelTag valid : " << valid() << std::endl;
    std::cout << "FrameLabelTag code: " << code() << std::endl;
    std::cout << "FrameLabelTag dataLength: " << dataLength() << std::endl;
    std::cout << "FrameLabelTag totalLength: " << totalLength() << std::endl;
}
