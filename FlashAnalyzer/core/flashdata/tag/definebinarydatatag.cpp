#include "definebinarydatatag.h"

#include <iostream>

DefineBinaryDataTag::DefineBinaryDataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_BINARY_DATA_TAG, headerLength, dataLength)
{
}

void DefineBinaryDataTag::print() const
{
    std::cout << "DefineBinaryDataTag valid : " << valid() << std::endl;
    std::cout << "DefineBinaryDataTag code: " << code() << std::endl;
    std::cout << "DefineBinaryDataTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineBinaryDataTag totalLength: " << totalLength() << std::endl;
}
