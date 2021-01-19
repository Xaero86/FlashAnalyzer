#ifndef ENDTAG_H
#define ENDTAG_H

#include "controltag.h"

class EndTag : public ControlTag
{
public:
    EndTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // ENDTAG_H
