#include "framelabeltag.h"

FrameLabelTag::FrameLabelTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, FRAME_LABEL_TAG, headerLength, dataLength)
{
}

std::string FrameLabelTag::tagType() const
{
	return "FrameLabel";
}

std::string FrameLabelTag::tagDescription() const
{
	return Tag::tagDescription();
}
