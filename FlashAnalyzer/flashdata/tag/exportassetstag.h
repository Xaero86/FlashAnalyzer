#ifndef EXPORTASSETSTAG_H
#define EXPORTASSETSTAG_H

#include "controltag.h"

class ExportAssetsTag : public ControlTag
{
public:
    ExportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // EXPORTASSETSTAG_H
