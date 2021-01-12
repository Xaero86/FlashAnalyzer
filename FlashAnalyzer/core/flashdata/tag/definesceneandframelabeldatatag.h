#ifndef DEFINESCENEANDFRAMELABELDATATAG_H
#define DEFINESCENEANDFRAMELABELDATATAG_H

#include "tag.h"

class DefineSceneAndFrameLabelDataTag : public Tag
{
public:
    DefineSceneAndFrameLabelDataTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINESCENEANDFRAMELABELDATATAG_H
