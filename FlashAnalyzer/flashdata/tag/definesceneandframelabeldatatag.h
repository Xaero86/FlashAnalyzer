#ifndef DEFINESCENEANDFRAMELABELDATATAG_H
#define DEFINESCENEANDFRAMELABELDATATAG_H

#include "tag.h"

class DefineSceneAndFrameLabelDataTag : public Tag
{
public:
    DefineSceneAndFrameLabelDataTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINESCENEANDFRAMELABELDATATAG_H
