#ifndef PLACEOBJECTTAG_H
#define PLACEOBJECTTAG_H

#include "controltag.h"
#include "datatypes.h"

class PlaceObjectTag : public ControlTag
{
public:
    PlaceObjectTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
    
private:
    uint16_t      _characterId;
    uint16_t      _depth;
    MatrixRecord  _matrix;
    CXFormRecord  _colorTransform;
};

#endif // PLACEOBJECTTAG_H
