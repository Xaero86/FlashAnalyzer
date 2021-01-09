#ifndef DEFINESHAPETAG_H
#define DEFINESHAPETAG_H

#include "definitiontag.h"
#include "datatypes.h"

class DefineShapeTag : public DefinitionTag
{
public:
    DefineShapeTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
    
private:
    RectangleRecord  _shapeBounds;
    // ShapeWithStyleRecord _shapes[]; //TODO
};

#endif // DEFINESHAPETAG_H
