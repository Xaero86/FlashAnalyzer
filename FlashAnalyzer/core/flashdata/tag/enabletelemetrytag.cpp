#include "enabletelemetrytag.h"

#include <iostream>

EnableTelemetryTag::EnableTelemetryTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, ENABLE_TELEMETRY_TAG, headerLength, dataLength)
{
}

void EnableTelemetryTag::print() const
{
    std::cout << "EnableTelemetryTag valid : " << valid() << std::endl;
    std::cout << "EnableTelemetryTag code: " << code() << std::endl;
    std::cout << "EnableTelemetryTag dataLength: " << dataLength() << std::endl;
    std::cout << "EnableTelemetryTag totalLength: " << totalLength() << std::endl;
}
