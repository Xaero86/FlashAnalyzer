#include "definescalinggridtag.h"

#include <iostream>

DefineScalingGridTag::DefineScalingGridTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SCALING_GRID_TAG, headerLength, dataLength)
{
}

void DefineScalingGridTag::print() const
{
    std::cout << "DefineScalingGridTag valid : " << valid() << std::endl;
    std::cout << "DefineScalingGridTag code: " << code() << std::endl;
    std::cout << "DefineScalingGridTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineScalingGridTag totalLength: " << totalLength() << std::endl;
}
