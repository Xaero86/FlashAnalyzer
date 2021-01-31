#ifndef FRAMELABELTAG_H
#define FRAMELABELTAG_H

#include "controltag.h"

class FrameLabelTag : public ControlTag
{
public:
    FrameLabelTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // FRAMELABELTAG_H
