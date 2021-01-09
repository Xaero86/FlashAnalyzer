#include "defineshapetag.h"

#include <iostream>

#include "tools.h"

DefineShapeTag::DefineShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_SHAPE_TAG, headerLength, dataLength),
 _shapeBounds()
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _shapeBounds.create(&_rawData[currentIndex], totalLength() - currentIndex);
    
    // ShapeWithStyleRecord _shapes[]; //TODO
}

void DefineShapeTag::print() const
{
    std::cout << "DefineShapeTag valid : " << valid() << std::endl;
    std::cout << "DefineShapeTag code: " << code() << std::endl;
    std::cout << "DefineShapeTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineShapeTag totalLength: " << totalLength() << std::endl;
}
