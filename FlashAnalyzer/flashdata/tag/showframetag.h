#ifndef SHOWFRAMETAG_H
#define SHOWFRAMETAG_H

#include "controltag.h"

class ShowFrameTag : public ControlTag
{
public:
    ShowFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // SHOWFRAMETAG_H
