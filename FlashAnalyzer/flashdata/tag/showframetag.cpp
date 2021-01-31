#include "showframetag.h"

ShowFrameTag::ShowFrameTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SHOW_FRAME_TAG, headerLength, dataLength)
{
}

std::string ShowFrameTag::tagType() const
{
	return "ShowFrame";
}

std::string ShowFrameTag::tagDescription() const
{
	return Tag::tagDescription();
}
