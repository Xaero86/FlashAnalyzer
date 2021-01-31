#ifndef JPEGTABLESTAG_H
#define JPEGTABLESTAG_H

#include "tag.h"

class JPEGTablesTag : public Tag
{
public:
    JPEGTablesTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
    
    const char* imageData() const {return _jpegData;}
    uint32_t imageDataSize() const {return _jpegDataSize;}
        
private:
    const char*  _jpegData;
    uint32_t     _jpegDataSize;
};

#endif // JPEGTABLESTAG_H
