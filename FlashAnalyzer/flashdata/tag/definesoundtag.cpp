#include "definesoundtag.h"

#include "tools.h"

DefineSoundTag::DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 DefinitionTag(source, DEFINE_SOUND_TAG, headerLength, dataLength)
{
	uint32_t currentIndex = headerLength;
	_uid = readUnsigned16(&_rawData[currentIndex]);
	//currentIndex += sizeof(_uid);
}

std::string DefineSoundTag::tagType() const
{
	return "DefineSound";
}

std::string DefineSoundTag::tagDescription() const
{
	return DefinitionTag::tagDescription();
}

std::string DefineSoundTag::extensionFile() const
{
	return std::string();
}

void DefineSoundTag::extract(QDataStream & /*outputFile*/)
{
	// TODO
}
