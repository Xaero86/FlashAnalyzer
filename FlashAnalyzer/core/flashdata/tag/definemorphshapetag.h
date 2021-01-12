#ifndef DEFINEMORPHSHAPETAG_H
#define DEFINEMORPHSHAPETAG_H

#include "tag.h"

class DefineMorphShapeTag : public Tag
{
public:
    DefineMorphShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // DEFINEMORPHSHAPETAG_H
