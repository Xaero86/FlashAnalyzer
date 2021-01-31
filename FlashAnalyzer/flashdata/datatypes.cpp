#include "datatypes.h"

#include <iostream>

#include "tools.h"

void RectangleRecord::create(const char* source, uint32_t dataMax)
{
    uint32_t currentBitIndex = 0;

    unsigned char nBits = (unsigned char) readUnsignedUnaligned(source, currentBitIndex, 5);
    currentBitIndex += 5;

    uint32_t requestedData = bitToByte(currentBitIndex + 4*nBits) + 1;
    if (dataMax < requestedData)
    {
        _valid = false;
        // not enough data available
        std::cerr << "Error parsing rectangle" << std::endl;
        return;
    }
    
    _xMin = readSignedUnaligned(source, currentBitIndex, nBits);
    currentBitIndex += nBits;
    _xMax = readSignedUnaligned(source, currentBitIndex, nBits);
    currentBitIndex += nBits;
    _yMin = readSignedUnaligned(source, currentBitIndex, nBits);
    currentBitIndex += nBits;
    _yMax = readSignedUnaligned(source, currentBitIndex, nBits);
    currentBitIndex += nBits;
    // index of currentBitIndex
    _dataSize = bitToByte(currentBitIndex)+1;
    _valid = true;
}

void MatrixRecord::create(const char* source, uint32_t dataMax)
{
    uint32_t currentBitIndex = 0;
    
    _hasScale = (readUnsignedUnaligned(source, currentBitIndex, 1) != 0);
    currentBitIndex += 1;
    
    if (_hasScale)
    {
        unsigned char nScaleBits = (unsigned char) readUnsignedUnaligned(source, currentBitIndex, 5);
        currentBitIndex += 5;
        
        uint32_t requestedData = bitToByte(currentBitIndex + 2*nScaleBits) + 1;
        if (dataMax < requestedData)
        {
            _valid = false;
            // not enough data available
            std::cerr << "Error parsing matrix" << std::endl;
            return;
        }
        
        _scaleX = readSignedUnaligned(source, currentBitIndex, nScaleBits);
        currentBitIndex += nScaleBits;
        _scaleY = readSignedUnaligned(source, currentBitIndex, nScaleBits);
        currentBitIndex += nScaleBits;
    }
    
    _hasRotate = (readUnsignedUnaligned(source, currentBitIndex, 1) != 0);
    currentBitIndex += 1;
    
    if (_hasRotate)
    {
        unsigned char nRotateBits = (unsigned char) readUnsignedUnaligned(source, currentBitIndex, 5);
        currentBitIndex += 5;
        
        uint32_t requestedData = bitToByte(currentBitIndex + 2*nRotateBits) + 1;
        if (dataMax < requestedData)
        {
            _valid = false;
            // not enough data available
            std::cerr << "Error parsing matrix" << std::endl;
            return;
        }
        
        _rotateSkew0 = readSignedUnaligned(source, currentBitIndex, nRotateBits);
        currentBitIndex += nRotateBits;
        _rotateSkew1 = readSignedUnaligned(source, currentBitIndex, nRotateBits);
        currentBitIndex += nRotateBits;
    }
    
    unsigned char nTranslateBits = (unsigned char) readUnsignedUnaligned(source, currentBitIndex, 5);
    currentBitIndex += 5;

    uint32_t requestedData = bitToByte(currentBitIndex + 2*nTranslateBits) + 1;
    if (dataMax < requestedData)
    {
        _valid = false;
        // not enough data available
        std::cerr << "Error parsing rectangle" << std::endl;
        return;
    }
    
    _translateX = readSignedUnaligned(source, currentBitIndex, nTranslateBits);
    currentBitIndex += nTranslateBits;
    _translateY = readSignedUnaligned(source, currentBitIndex, nTranslateBits);
    currentBitIndex += nTranslateBits;
    // index of currentBitIndex
    _dataSize = bitToByte(currentBitIndex)+1;
    _valid = true;
}

void CXFormRecord::create(const char* source, uint32_t dataMax)
{
    uint32_t currentBitIndex = 0;
    
    _hasAddTerms = (readUnsignedUnaligned(source, currentBitIndex, 1) != 0);
    currentBitIndex += 1;
    
    _hasMultTerms = (readUnsignedUnaligned(source, currentBitIndex, 1) != 0);
    currentBitIndex += 1;
    
    unsigned char nBits = (unsigned char) readUnsignedUnaligned(source, currentBitIndex, 4);
    currentBitIndex += 4;
    
    if (_hasAddTerms)
    {
        uint32_t requestedData = bitToByte(currentBitIndex + 3*nBits) + 1;
        if (dataMax < requestedData)
        {
            _valid = false;
            // not enough data available
            std::cerr << "Error parsing CXForm" << std::endl;
            return;
        }
        
        _redMultTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
        _greenMultTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
        _blueMultTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
    }
    
    if (_hasMultTerms)
    {
        uint32_t requestedData = bitToByte(currentBitIndex + 3*nBits) + 1;
        if (dataMax < requestedData)
        {
            _valid = false;
            // not enough data available
            std::cerr << "Error parsing CXForm" << std::endl;
            return;
        }
        
        _redAddTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
        _greenAddTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
        _blueAddTerm = readSignedUnaligned(source, currentBitIndex, nBits);
        currentBitIndex += nBits;
    }
    
    // index of currentBitIndex
    _dataSize = bitToByte(currentBitIndex)+1;
    _valid = true;
}

void RGBRecord::create(const char* source, uint32_t dataMax)
{
    if (dataMax < 3)
    {
        _valid = false;
        // not enough data available
        std::cerr << "Error parsing RGB" << std::endl;
        return;
    }
    
    _valid = true;
    _red = source[0];
    _green = source[1];
    _blue = source[2];
}

void RGBARecord::create(const char* source, uint32_t dataMax)
{
    if (dataMax < 4)
    {
        _valid = false;
        // not enough data available
        std::cerr << "Error parsing RGBA" << std::endl;
        return;
    }
    
    _valid = true;
    _red = source[0];
    _green = source[1];
    _blue = source[2];
    _alpha = source[3];
}

void ARGBRecord::create(const char* source, uint32_t dataMax)
{
    if (dataMax < 4)
    {
        _valid = false;
        // not enough data available
        std::cerr << "Error parsing ARGB" << std::endl;
        return;
    }
    
    _valid = true;
    _alpha = source[0];
    _red = source[1];
    _green = source[2];
    _blue = source[3];
}
