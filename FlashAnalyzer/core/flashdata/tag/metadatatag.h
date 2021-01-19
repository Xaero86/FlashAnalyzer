#ifndef METADATATAG_H
#define METADATATAG_H

#include "controltag.h"

class MetadataTag : public ControlTag
{
public:
    MetadataTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // METADATATAG_H
