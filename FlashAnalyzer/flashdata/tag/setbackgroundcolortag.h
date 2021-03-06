#ifndef SETBACKGROUNDCOLORTAG_H
#define SETBACKGROUNDCOLORTAG_H

#include "controltag.h"
#include "datatypes.h"

class SetBackgroundColorTag : public ControlTag
{
public:
    SetBackgroundColorTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
        
private:
    RGBRecord  _color;
};

#endif // SETBACKGROUNDCOLORTAG_H
