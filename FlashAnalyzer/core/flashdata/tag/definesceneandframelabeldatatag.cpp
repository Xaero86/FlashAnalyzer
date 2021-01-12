#include "definesceneandframelabeldatatag.h"

DefineSceneAndFrameLabelDataTag::DefineSceneAndFrameLabelDataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SCENE_AND_FRAME_LABEL_DATA_TAG, headerLength, dataLength)
{
}

std::string DefineSceneAndFrameLabelDataTag::tagType() const
{
	return "DefineSceneAndFrameLabelData";
}

std::string DefineSceneAndFrameLabelDataTag::tagDescription() const
{
	return Tag::tagDescription();
}
