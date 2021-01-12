#include "definespritetag.h"

#include <iostream>
#include <sstream>

#include "tools.h"

DefineSpriteTag::DefineSpriteTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_SPRITE_TAG, headerLength, dataLength),
 _frameCount(0),
 _tags()
{
    uint32_t currentIndex = headerLength;
    _uid = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_uid);
    
    _frameCount = readUnsigned16(&_rawData[currentIndex]);
    currentIndex += sizeof(_frameCount);

	Tag* newTag;

    while (dataLength > currentIndex)
    {
		newTag = Tag::AddNextTag(&_rawData[currentIndex], dataLength-currentIndex, _tags);
		if ((newTag->totalLength() > 0) && newTag->valid())
		{
			newTag->setParent(this);
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

std::string DefineSpriteTag::tagType() const
{
	return "DefineSprite";
}

std::string DefineSpriteTag::tagDescription() const
{
	std::stringstream description;

	description << Tag::tagDescription();
	description << "Number of tags: " << _tags.size() << std::endl;

	return description.str();
}
