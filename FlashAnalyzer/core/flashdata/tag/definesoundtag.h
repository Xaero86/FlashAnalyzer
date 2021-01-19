#ifndef DEFINESOUNDTAG_H
#define DEFINESOUNDTAG_H

#include "definitiontag.h"
#include "extractabletag.h"

class DefineSoundTag : public DefinitionTag, ExtractableTag
{
public:
    DefineSoundTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;

	std::string extensionFile() const override;
	void extract(std::ofstream& outputFile) override;
};

#endif // DEFINESOUNDTAG_H
