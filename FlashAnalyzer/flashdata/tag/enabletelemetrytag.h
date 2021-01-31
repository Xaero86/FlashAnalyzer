#ifndef ENABLETELEMETRYTAG_H
#define ENABLETELEMETRYTAG_H

#include "tag.h"

class EnableTelemetryTag : public Tag
{
public:
    EnableTelemetryTag(const char* source, uint32_t headerLength, uint32_t dataLength);

	std::string tagType() const override;
	std::string tagDescription() const override;
};

#endif // ENABLETELEMETRYTAG_H
