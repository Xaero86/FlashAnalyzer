#ifndef ENABLEDEBUGGERTAG_H
#define ENABLEDEBUGGERTAG_H

#include "tag.h"

class EnableDebuggerTag : public Tag
{
public:
    EnableDebuggerTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // ENABLEDEBUGGERTAG_H
