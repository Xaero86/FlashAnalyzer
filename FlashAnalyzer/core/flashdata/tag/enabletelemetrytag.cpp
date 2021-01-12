#include "enabletelemetrytag.h"

EnableTelemetryTag::EnableTelemetryTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, ENABLE_TELEMETRY_TAG, headerLength, dataLength)
{
}

std::string EnableTelemetryTag::tagType() const
{
	return "EnableTelemetry";
}

std::string EnableTelemetryTag::tagDescription() const
{
	return Tag::tagDescription();
}
