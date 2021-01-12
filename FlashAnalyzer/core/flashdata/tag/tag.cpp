#include "tag.h"

#include <iostream>
#include <sstream>

#include "tools.h"

#include "endtag.h"
#include "showframetag.h"
#include "defineshapetag.h"
#include "placeobjecttag.h"
#include "removeobjecttag.h"
#include "definebitstag.h"
#include "definebuttontag.h"
#include "jpegtablestag.h"
#include "setbackgroundcolortag.h"
#include "definefonttag.h"
#include "definetexttag.h"
#include "doactiontag.h"
#include "definefontinfotag.h"
#include "definesoundtag.h"
#include "startsoundtag.h"
#include "definebuttonsoundtag.h"
#include "soundstreamheadtag.h"
#include "soundstreamblocktag.h"
#include "definebitslosslesstag.h"
#include "definebitsjpeg2tag.h"
#include "defineshape2tag.h"
#include "definebuttoncxformtag.h"
#include "protecttag.h"
#include "placeobject2tag.h"
#include "removeobject2tag.h"
#include "defineshape3tag.h"
#include "definetext2tag.h"
#include "definebutton2tag.h"
#include "definebitsjpeg3tag.h"
#include "definebitslossless2tag.h"
#include "defineedittexttag.h"
#include "definespritetag.h"
#include "framelabeltag.h"
#include "soundstreamhead2tag.h"
#include "definemorphshapetag.h"
#include "definefont2tag.h"
#include "exportassetstag.h"
#include "importassetstag.h"
#include "enabledebuggertag.h"
#include "doinitactiontag.h"
#include "definevideostreamtag.h"
#include "videoframetag.h"
#include "definefontinfo2tag.h"
#include "enabledebugger2tag.h"
#include "scriptlimitstag.h"
#include "settabindextag.h"
#include "fileattributestag.h"
#include "placeobject3tag.h"
#include "importassets2tag.h"
#include "definefontalignzonestag.h"
#include "csmtextsettingstag.h"
#include "definefont3tag.h"
#include "symbolclasstag.h"
#include "metadatatag.h"
#include "definescalinggridtag.h"
#include "doabctag.h"
#include "defineshape4tag.h"
#include "definemorphshape2tag.h"
#include "definesceneandframelabeldatatag.h"
#include "definebinarydatatag.h"
#include "definefontnametag.h"
#include "startsound2tag.h"
#include "definebitsjpeg4tag.h"
#include "definefont4tag.h"
#include "enabletelemetrytag.h"

Tag *Tag::AddNextTag(const char* source, uint32_t dataMax, tags_t &tags)
{
    uint16_t header = 0;
    
    if (dataMax < sizeof(header))
    {
        // not enough data available
        std::cerr << "Error parsing tag header" << std::endl;
		return nullptr;
    }
    header = readUnsigned16(source);
    
    uint32_t code = (header & 0xFFC0) >> 6;
    uint32_t dataLength = header & 0x003F;
    uint32_t headerLength = sizeof(header);
    
    if (dataLength == 0x3F)
    {
        if (dataMax < sizeof(header) + sizeof(dataLength))
        {
            // not enough data available
            std::cerr << "Error parsing tag header" << std::endl;
			return nullptr;
        }
        dataLength = readUnsigned32(&source[sizeof(header)]);
		headerLength += sizeof(dataLength);
    }
    
    switch (code)
    {
        case END_TAG:
			tags.push_back(std::unique_ptr<EndTag>(new EndTag(source, headerLength, dataLength)));
            break;
        case SHOW_FRAME_TAG:
			tags.push_back(std::unique_ptr<ShowFrameTag>(new ShowFrameTag(source, headerLength, dataLength)));
            break;
        case DEFINE_SHAPE_TAG:
			tags.push_back(std::unique_ptr<DefineShapeTag>(new DefineShapeTag(source, headerLength, dataLength)));
            break;
        case PLACE_OBJECT_TAG:
			tags.push_back(std::unique_ptr<PlaceObjectTag>(new PlaceObjectTag(source, headerLength, dataLength)));
            break;
        case REMOVE_OBJECT_TAG:
			tags.push_back(std::unique_ptr<RemoveObjectTag>(new RemoveObjectTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_TAG:
			tags.push_back(std::unique_ptr<DefineBitsTag>(new DefineBitsTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BUTTON_TAG:
			tags.push_back(std::unique_ptr<DefineButtonTag>(new DefineButtonTag(source, headerLength, dataLength)));
            break;
        case JPEG_TABLES_TAG:
			tags.push_back(std::unique_ptr<JPEGTablesTag>(new JPEGTablesTag(source, headerLength, dataLength)));
            break;
        case SET_BACKGROUND_COLOR_TAG:
			tags.push_back(std::unique_ptr<SetBackgroundColorTag>(new SetBackgroundColorTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_TAG:
			tags.push_back(std::unique_ptr<DefineFontTag>(new DefineFontTag(source, headerLength, dataLength)));
            break;
        case DEFINE_TEXT_TAG:
			tags.push_back(std::unique_ptr<DefineTextTag>(new DefineTextTag(source, headerLength, dataLength)));
            break;
        case DO_ACTION_TAG:
			tags.push_back(std::unique_ptr<DoActionTag>(new DoActionTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_INFO_TAG:
			tags.push_back(std::unique_ptr<DefineFontInfoTag>(new DefineFontInfoTag(source, headerLength, dataLength)));
            break;
        case DEFINE_SOUND_TAG:
			tags.push_back(std::unique_ptr<DefineSoundTag>(new DefineSoundTag(source, headerLength, dataLength)));
            break;
        case START_SOUND_TAG:
			tags.push_back(std::unique_ptr<StartSoundTag>(new StartSoundTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BUTTON_SOUND_TAG:
			tags.push_back(std::unique_ptr<DefineButtonSoundTag>(new DefineButtonSoundTag(source, headerLength, dataLength)));
            break;
        case SOUND_STREAM_HEAD_TAG:
			tags.push_back(std::unique_ptr<SoundStreamHeadTag>(new SoundStreamHeadTag(source, headerLength, dataLength)));
            break;
        case SOUND_STREAM_BLOCK_TAG:
			tags.push_back(std::unique_ptr<SoundStreamBlockTag>(new SoundStreamBlockTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_LOSSLESS_TAG:
			tags.push_back(std::unique_ptr<DefineBitsLosslessTag>(new DefineBitsLosslessTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_JPEG_2_TAG:
			tags.push_back(std::unique_ptr<DefineBitsJPEG2Tag>(new DefineBitsJPEG2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_SHAPE_2_TAG:
			tags.push_back(std::unique_ptr<DefineShape2Tag>(new DefineShape2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_BUTTON_CXFORM_TAG:
			tags.push_back(std::unique_ptr<DefineButtonCxformTag>(new DefineButtonCxformTag(source, headerLength, dataLength)));
            break;
        case PROTECT_TAG:
			tags.push_back(std::unique_ptr<ProtectTag>(new ProtectTag(source, headerLength, dataLength)));
            break;
        case PLACE_OBJECT_2_TAG:
			tags.push_back(std::unique_ptr<PlaceObject2Tag>(new PlaceObject2Tag(source, headerLength, dataLength)));
            break;
        case REMOVE_OBJECT_2_TAG:
			tags.push_back(std::unique_ptr<RemoveObject2Tag>(new RemoveObject2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_SHAPE_3_TAG:
			tags.push_back(std::unique_ptr<DefineShape3Tag>(new DefineShape3Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_TEXT_2_TAG:
			tags.push_back(std::unique_ptr<DefineText2Tag>(new DefineText2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_BUTTON_2_TAG:
			tags.push_back(std::unique_ptr<DefineButton2Tag>(new DefineButton2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_JPEG_3_TAG:
			tags.push_back(std::unique_ptr<DefineBitsJPEG3Tag>(new DefineBitsJPEG3Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_LOSSLESS_2_TAG:
			tags.push_back(std::unique_ptr<DefineBitsLossless2Tag>(new DefineBitsLossless2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_EDIT_TEXT_TAG:
			tags.push_back(std::unique_ptr<DefineEditTextTag>(new DefineEditTextTag(source, headerLength, dataLength)));
            break;
        case DEFINE_SPRITE_TAG:
			tags.push_back(std::unique_ptr<DefineSpriteTag>(new DefineSpriteTag(source, headerLength, dataLength)));
            break;
        case FRAME_LABEL_TAG:
			tags.push_back(std::unique_ptr<FrameLabelTag>(new FrameLabelTag(source, headerLength, dataLength)));
            break;
        case SOUND_STREAM_HEAD_2_TAG:
			tags.push_back(std::unique_ptr<SoundStreamHead2Tag>(new SoundStreamHead2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_MORPH_SHAPE_TAG:
			tags.push_back(std::unique_ptr<DefineMorphShapeTag>(new DefineMorphShapeTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_2_TAG:
			tags.push_back(std::unique_ptr<DefineFont2Tag>(new DefineFont2Tag(source, headerLength, dataLength)));
            break;
        case EXPORT_ASSETS_TAG:
			tags.push_back(std::unique_ptr<ExportAssetsTag>(new ExportAssetsTag(source, headerLength, dataLength)));
            break;
        case IMPORT_ASSETS_TAG:
			tags.push_back(std::unique_ptr<ImportAssetsTag>(new ImportAssetsTag(source, headerLength, dataLength)));
            break;
        case ENABLE_DEBUGGER_TAG:
			tags.push_back(std::unique_ptr<EnableDebuggerTag>(new EnableDebuggerTag(source, headerLength, dataLength)));
            break;
        case DO_INIT_ACTION_TAG:
			tags.push_back(std::unique_ptr<DoInitActionTag>(new DoInitActionTag(source, headerLength, dataLength)));
            break;
        case DEFINE_VIDEO_STREAM_TAG:
			tags.push_back(std::unique_ptr<DefineVideoStreamTag>(new DefineVideoStreamTag(source, headerLength, dataLength)));
            break;
        case VIDEO_FRAME_TAG:
			tags.push_back(std::unique_ptr<VideoFrameTag>(new VideoFrameTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_INFO_2_TAG:
			tags.push_back(std::unique_ptr<DefineFontInfo2Tag>(new DefineFontInfo2Tag(source, headerLength, dataLength)));
            break;
        case ENABLE_DEBUGGER_2_TAG:
			tags.push_back(std::unique_ptr<EnableDebugger2Tag>(new EnableDebugger2Tag(source, headerLength, dataLength)));
            break;
        case SCRIPT_LIMITS_TAG:
			tags.push_back(std::unique_ptr<ScriptLimitsTag>(new ScriptLimitsTag(source, headerLength, dataLength)));
            break;
        case SET_TAB_INDEX_TAG:
			tags.push_back(std::unique_ptr<SetTabIndexTag>(new SetTabIndexTag(source, headerLength, dataLength)));
            break;
        case FILE_ATTRIBUTES_TAG:
			tags.push_back(std::unique_ptr<FileAttributesTag>(new FileAttributesTag(source, headerLength, dataLength)));
            break;
        case PLACE_OBJECT_3_TAG:
			tags.push_back(std::unique_ptr<PlaceObject3Tag>(new PlaceObject3Tag(source, headerLength, dataLength)));
            break;
        case IMPORT_ASSETS_2_TAG:
			tags.push_back(std::unique_ptr<ImportAssets2Tag>(new ImportAssets2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_ALIGN_ZONES_TAG:
			tags.push_back(std::unique_ptr<DefineFontAlignZonesTag>(new DefineFontAlignZonesTag(source, headerLength, dataLength)));
            break;
        case CSM_TEXT_SETTINGS_TAG:
			tags.push_back(std::unique_ptr<CSMTextSettingsTag>(new CSMTextSettingsTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_3_TAG:
			tags.push_back(std::unique_ptr<DefineFont3Tag>(new DefineFont3Tag(source, headerLength, dataLength)));
            break;
        case SYMBOL_CLASS_TAG:
			tags.push_back(std::unique_ptr<SymbolClassTag>(new SymbolClassTag(source, headerLength, dataLength)));
            break;
        case METADATA_TAG:
			tags.push_back(std::unique_ptr<MetadataTag>(new MetadataTag(source, headerLength, dataLength)));
            break;
        case DEFINE_SCALING_GRID_TAG:
			tags.push_back(std::unique_ptr<DefineScalingGridTag>(new DefineScalingGridTag(source, headerLength, dataLength)));
            break;
        case DO_ABC_TAG:
			tags.push_back(std::unique_ptr<DoABCTag>(new DoABCTag(source, headerLength, dataLength)));
            break;
        case DEFINE_SHAPE_4_TAG:
			tags.push_back(std::unique_ptr<DefineShape4Tag>(new DefineShape4Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_MORPH_SHAPE_2_TAG:
			tags.push_back(std::unique_ptr<DefineMorphShape2Tag>(new DefineMorphShape2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_SCENE_AND_FRAME_LABEL_DATA_TAG:
			tags.push_back(std::unique_ptr<DefineSceneAndFrameLabelDataTag>(new DefineSceneAndFrameLabelDataTag(source, headerLength, dataLength)));
            break;
        case DEFINE_BINARY_DATA_TAG:
			tags.push_back(std::unique_ptr<DefineBinaryDataTag>(new DefineBinaryDataTag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_NAME_TAG:
			tags.push_back(std::unique_ptr<DefineFontNameTag>(new DefineFontNameTag(source, headerLength, dataLength)));
            break;
        case START_SOUND_2_TAG:
			tags.push_back(std::unique_ptr<StartSound2Tag>(new StartSound2Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_BITS_JPEG_4_TAG:
			tags.push_back(std::unique_ptr<DefineBitsJPEG4Tag>(new DefineBitsJPEG4Tag(source, headerLength, dataLength)));
            break;
        case DEFINE_FONT_4_TAG:
			tags.push_back(std::unique_ptr<DefineFont4Tag>(new DefineFont4Tag(source, headerLength, dataLength)));
            break;
        case ENABLE_TELEMETRY_TAG:
			tags.push_back(std::unique_ptr<EnableTelemetryTag>(new EnableTelemetryTag(source, headerLength, dataLength)));
            break;
        default:
			tags.push_back(std::unique_ptr<Tag>(new Tag(source, code, headerLength, dataLength)));
            break;
    }
	return tags.back().get();
}

Tag::Tag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
 _rawData(source),
 _valid(true),
 _code(code),
 _headerLength(headerLength),
 _dataLength(dataLength),
  _parent(nullptr)
{}

std::string Tag::tagType() const
{
	return "Unknown tag";
}

std::string Tag::tagDescription() const
{
	std::stringstream description;

	description << "Valid: " << valid() << std::endl;
	description << "Code: " << code() << std::endl;
	description << "DataLength: " << dataLength() << std::endl;
	description << "TotalLength: " << totalLength() << std::endl;

	return description.str();
}
bool Tag::isImage() const
{
	return ((_code == DEFINE_BITS_TAG) ||
			(_code == DEFINE_BITS_LOSSLESS_TAG) ||
			(_code == DEFINE_BITS_JPEG_2_TAG) ||
			(_code == DEFINE_BITS_JPEG_3_TAG) ||
			(_code == DEFINE_BITS_LOSSLESS_2_TAG) ||
			(_code == DEFINE_BITS_JPEG_4_TAG));
}

bool Tag::isVideo() const
{
	return (_code == DEFINE_VIDEO_STREAM_TAG);
}

bool Tag::isSound() const
{
	return (_code == DEFINE_SOUND_TAG);
}
