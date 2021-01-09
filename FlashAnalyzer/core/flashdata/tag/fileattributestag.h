#ifndef FILEATTRIBUTESTAG_H
#define FILEATTRIBUTESTAG_H

#include "tag.h"

class FileAttributesTag : public Tag
{
public:
    FileAttributesTag(const char* source, uint32_t headerLength, uint32_t dataLength);
    
    bool hasMetaData() const {return _hasMetaData;}
    bool hasAS3() const {return _hasAS3;}
    bool noCrossDomainCache() const {return _noCrossDomainCache;}
    bool useNetwork() const {return _useNetwork;}
    
    void print() const;
    
private:
    bool   _hasMetaData;
    bool   _hasAS3;
    bool   _noCrossDomainCache;
    bool   _useNetwork;
};

#endif // FILEATTRIBUTESTAG_H
