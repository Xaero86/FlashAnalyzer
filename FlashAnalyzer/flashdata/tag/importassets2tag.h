#ifndef IMPORTASSETS2TAG_H
#define IMPORTASSETS2TAG_H

#include "controltag.h"

class ImportAssets2Tag : public ControlTag
{
public:
    ImportAssets2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // IMPORTASSETS2TAG_H
