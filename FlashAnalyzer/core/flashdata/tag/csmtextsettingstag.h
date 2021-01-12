#ifndef CSMTEXTSETTINGSTAG_H
#define CSMTEXTSETTINGSTAG_H

#include "tag.h"

class CSMTextSettingsTag : public Tag
{
public:
    CSMTextSettingsTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // CSMTEXTSETTINGSTAG_H
