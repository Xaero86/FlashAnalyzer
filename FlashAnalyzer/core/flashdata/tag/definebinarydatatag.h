#ifndef DEFINEBINARYDATATAG_H
#define DEFINEBINARYDATATAG_H

#include "tag.h"

class DefineBinaryDataTag : public Tag
{
public:
    DefineBinaryDataTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINEBINARYDATATAG_H
