#ifndef ENABLEDEBUGGER2TAG_H
#define ENABLEDEBUGGER2TAG_H

#include "controltag.h"

class EnableDebugger2Tag : public ControlTag
{
public:
    EnableDebugger2Tag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // ENABLEDEBUGGER2TAG_H
