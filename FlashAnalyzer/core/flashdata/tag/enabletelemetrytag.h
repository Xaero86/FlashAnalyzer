#ifndef ENABLETELEMETRYTAG_H
#define ENABLETELEMETRYTAG_H

#include "tag.h"

class EnableTelemetryTag : public Tag
{
public:
    EnableTelemetryTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const;
	std::string tagDescription() const;
};

#endif // ENABLETELEMETRYTAG_H
