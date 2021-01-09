#include "definespritetag.h"

#include <iostream>

#include "tools.h"

DefineSpriteTag::DefineSpriteTag(const char* source, uint32_t headerLength, uint32_t dataLength, SWFFile* swfFile) :
 DefinitionTag(source, DEFINE_SPRITE_TAG, headerLength, dataLength),
 _frameCount(0),
 _tags()
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _frameCount = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_frameCount);

    Tag* newTag = nullptr;
    
    while (dataLength > currentIndex)
    {
        newTag = Tag::CreateTag(&_rawData[currentIndex], dataLength-currentIndex, swfFile);
        if ((newTag != nullptr) && (newTag->totalLength() > 0) && newTag->valid())
        {
            _tags.push_back(newTag);
            currentIndex += newTag->totalLength();
        }
        else
        {
            _valid = false;
            std::cerr << "Fail to create tag" << std::endl;
            break;
        }
    }
}

void DefineSpriteTag::print() const
{
    std::cout << "DefineSpriteTag valid : " << valid() << std::endl;
    std::cout << "DefineSpriteTag code: " << code() << std::endl;
    std::cout << "DefineSpriteTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineSpriteTag totalLength: " << totalLength() << std::endl;

    for (Tag::const_iterator itTag = _tags.cbegin(); itTag != _tags.cend(); ++itTag)
    {
        (*itTag)->print();
    }
}
