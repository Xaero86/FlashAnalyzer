#ifndef SETTABINDEXTAG_H
#define SETTABINDEXTAG_H

#include "tag.h"

class SetTabIndexTag : public Tag
{
public:
    SetTabIndexTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SETTABINDEXTAG_H
