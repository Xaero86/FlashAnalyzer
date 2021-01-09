#ifndef EXPORTASSETSTAG_H
#define EXPORTASSETSTAG_H

#include "tag.h"

class ExportAssetsTag : public Tag
{
public:
    ExportAssetsTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    void print() const;
};

#endif // EXPORTASSETSTAG_H
