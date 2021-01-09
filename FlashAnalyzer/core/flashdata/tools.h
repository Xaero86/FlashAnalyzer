#ifndef TOOLS_H
#define TOOLS_H

#include <string>

uint16_t readUnsigned16(const char* source);
int16_t  readSigned16(const char* source);
uint32_t readUnsigned32(const char* source);
int32_t  readSigned32(const char* source);
uint64_t readUnsigned64(const char* source);
int64_t  readSigned64(const char* source);

void writeUnsigned16(char* dest, uint16_t val);
void writeSigned16(char* dest, int16_t val);
void writeUnsigned32(char* dest, uint32_t val);
void writeSigned32(char* dest, int32_t val);
void writeUnsigned64(char* dest, uint64_t val);
void writeSigned64(char* dest, int64_t val);

uint32_t bitToByte(uint32_t bitPos);
uint32_t readUnsignedUnaligned(const char* source, uint32_t bitPos, unsigned char nbBits);
int32_t  readSignedUnaligned(const char* source, uint32_t bitPos, unsigned char nbBits);

#endif // TOOLS_H
