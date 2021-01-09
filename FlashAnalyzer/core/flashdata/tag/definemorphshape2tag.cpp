#include "definemorphshape2tag.h"

#include <iostream>

DefineMorphShape2Tag::DefineMorphShape2Tag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_MORPH_SHAPE_2_TAG, headerLength, dataLength)
{
}

void DefineMorphShape2Tag::print() const
{
    std::cout << "DefineMorphShape2Tag valid : " << valid() << std::endl;
    std::cout << "DefineMorphShape2Tag code: " << code() << std::endl;
    std::cout << "DefineMorphShape2Tag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineMorphShape2Tag totalLength: " << totalLength() << std::endl;
}
