#ifndef ENABLEDEBUGGERTAG_H
#define ENABLEDEBUGGERTAG_H

#include "controltag.h"

class EnableDebuggerTag : public ControlTag
{
public:
    EnableDebuggerTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // ENABLEDEBUGGERTAG_H
