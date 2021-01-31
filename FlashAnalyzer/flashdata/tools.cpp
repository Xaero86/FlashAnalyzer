#include "tools.h"

#include <QtEndian>

uint16_t readUnsigned16(const char* source)
{
	return qFromLittleEndian<uint16_t>(source);
}

int16_t  readSigned16(const char* source)
{
	return qFromLittleEndian<int16_t>(source);
}

uint32_t readUnsigned32(const char* source)
{
	return qFromLittleEndian<uint32_t>(source);
}

int32_t  readSigned32(const char* source)
{
	return qFromLittleEndian<int32_t>(source);
}

uint64_t readUnsigned64(const char* source)
{
	return qFromLittleEndian<uint64_t>(source);
}

int64_t  readSigned64(const char* source)
{
	return qFromLittleEndian<int64_t>(source);
}

void writeUnsigned16(char* dest, uint16_t val)
{
	qToLittleEndian<uint16_t>(val, dest);
}

void writeSigned16(char* dest, int16_t val)
{
	qToLittleEndian<int16_t>(val, dest);
}

void writeUnsigned32(char* dest, uint32_t val)
{
	qToLittleEndian<uint32_t>(val, dest);
}

void writeSigned32(char* dest, int32_t val)
{
	qToLittleEndian<int32_t>(val, dest);
}

void writeUnsigned64(char* dest, uint64_t val)
{
	qToLittleEndian<uint64_t>(val, dest);
}

void writeSigned64(char* dest, int64_t val)
{
	qToLittleEndian<int64_t>(val, dest);
}

uint32_t bitToByte(uint32_t bitPos)
{
    return (bitPos == 0)?0:((bitPos - 1) / CHAR_BIT);
}

uint32_t readUnsignedUnaligned(const char* source, uint32_t bitPos, unsigned char nbBits)
{
    uint64_t result = 0;
    uint64_t mask = (1 << nbBits) - 1;
    
	memcpy(&result, &source[bitToByte(bitPos)], sizeof(uint64_t));
	result = qFromBigEndian<uint64_t>(result);
    result >>= sizeof(uint64_t) * CHAR_BIT - (nbBits + bitPos%CHAR_BIT);
    
    return (uint32_t) (result & mask);
}

int32_t  readSignedUnaligned(const char* source, uint32_t bitPos, unsigned char nbBits)
{
    uint64_t result = 0;
    uint64_t mask = (1 << (nbBits-1)) - 1;
    uint64_t signMask = 1 << (nbBits-1);
    
	memcpy(&result, &source[bitToByte(bitPos)], sizeof(uint64_t));
	result = qFromBigEndian<uint64_t>(result);
    result >>= sizeof(uint64_t) * CHAR_BIT - (nbBits + bitPos%CHAR_BIT);
    
    bool negative = (result & signMask);
    
    return (negative?-1:1)*((int32_t) (result & mask));
}
