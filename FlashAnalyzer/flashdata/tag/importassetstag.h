#ifndef IMPORTASSETSTAG_H
#define IMPORTASSETSTAG_H

#include "controltag.h"

class ImportAssetsTag : public ControlTag
{
public:
    ImportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // IMPORTASSETSTAG_H
