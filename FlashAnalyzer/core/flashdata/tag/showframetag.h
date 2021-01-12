#ifndef SHOWFRAMETAG_H
#define SHOWFRAMETAG_H

#include "controltag.h"

class ShowFrameTag : public ControlTag
{
public:
    ShowFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // SHOWFRAMETAG_H
