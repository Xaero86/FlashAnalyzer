#include "definesceneandframelabeldatatag.h"

#include <iostream>

DefineSceneAndFrameLabelDataTag::DefineSceneAndFrameLabelDataTag(const char* source, uint32_t headerLength, uint32_t dataLength) :
 Tag(source, DEFINE_SCENE_AND_FRAME_LABEL_DATA_TAG, headerLength, dataLength)
{
}

void DefineSceneAndFrameLabelDataTag::print() const
{
    std::cout << "DefineSceneAndFrameLabelDataTag valid : " << valid() << std::endl;
    std::cout << "DefineSceneAndFrameLabelDataTag code: " << code() << std::endl;
    std::cout << "DefineSceneAndFrameLabelDataTag dataLength: " << dataLength() << std::endl;
    std::cout << "DefineSceneAndFrameLabelDataTag totalLength: " << totalLength() << std::endl;
}
