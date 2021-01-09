#ifndef SETBACKGROUNDCOLORTAG_H
#define SETBACKGROUNDCOLORTAG_H

#include "controltag.h"
#include "datatypes.h"

class SetBackgroundColorTag : public ControlTag
{
public:
    SetBackgroundColorTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
        
private:
    RGBRecord  _color;
};

#endif // SETBACKGROUNDCOLORTAG_H
