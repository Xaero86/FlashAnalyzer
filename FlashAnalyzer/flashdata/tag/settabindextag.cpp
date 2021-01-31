#include "settabindextag.h"

SetTabIndexTag::SetTabIndexTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 ControlTag(source, SET_TAB_INDEX_TAG, headerLength, dataLength)
{
}

std::string SetTabIndexTag::tagType() const
{
	return "SetTabIndex";
}

std::string SetTabIndexTag::tagDescription() const
{
	return ControlTag::tagDescription();
}
