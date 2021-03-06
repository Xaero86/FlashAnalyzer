#ifndef REMOVEOBJECTTAG_H
#define REMOVEOBJECTTAG_H

#include "controltag.h"

class RemoveObjectTag : public ControlTag
{
public:
    RemoveObjectTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
        
private:
    uint16_t      _characterId;
    uint16_t      _depth;
};

#endif // REMOVEOBJECTTAG_H
