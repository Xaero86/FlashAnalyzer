#include "definemorphshapetag.h"

#include <iostream>

DefineMorphShapeTag::DefineMorphShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_MORPH_SHAPE_TAG, headerLength, dataLength)
{
}

void DefineMorphShapeTag::print() const
{
    std::cout << "DefineMorphShapeTag valid : " << valid() << std::endl;
    std::cout << "DefineMorphShapeTag code: " << code() << std::endl;
    std::cout << "DefineMorphShapeTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineMorphShapeTag totalLength: " << totalLength() << std::endl;
}
