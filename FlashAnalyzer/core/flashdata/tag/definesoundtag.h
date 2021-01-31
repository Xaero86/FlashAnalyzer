#ifndef DEFINESOUNDTAG_H
#define DEFINESOUNDTAG_H

#include "definitiontag.h"
#include "extractabletag.h"

class DefineSoundTag : public DefinitionTag, public ExtractableTag
{
public:
    DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	std::string extensionFile() const override;
	void extract(QDataStream &outputStream) override;
};

#endif // DEFINESOUNDTAG_H
