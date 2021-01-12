#ifndef IMPORTASSETSTAG_H
#define IMPORTASSETSTAG_H

#include "tag.h"

class ImportAssetsTag : public Tag
{
public:
    ImportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // IMPORTASSETSTAG_H
