#ifndef DEFINEBINARYDATATAG_H
#define DEFINEBINARYDATATAG_H

#include "tag.h"

class DefineBinaryDataTag : public Tag
{
public:
    DefineBinaryDataTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // DEFINEBINARYDATATAG_H
