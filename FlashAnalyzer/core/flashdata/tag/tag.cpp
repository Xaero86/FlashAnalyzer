#include "tag.h"

#include <iostream>

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

Tag* Tag::CreateTag(const char* source, uint32_t dataMax, SWFFile* swfFile)
{
    Tag* newTag = nullptr;
    uint16_t header = 0;
    
    if (dataMax < sizeof(header))
    {
        // not enough data available
        std::cerr << "Error parsing tag header" << std::endl;
        return newTag;
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
            return newTag;
        }
        dataLength = readUnsigned32(&source[sizeof(header)]);
        headerLength += sizeof(dataLength);
    }
    
    switch (code)
    {
        case END_TAG:
            newTag = new EndTag(source, headerLength, dataLength);
            break;
        case SHOW_FRAME_TAG:
            newTag = new ShowFrameTag(source, headerLength, dataLength);
            break;
        case DEFINE_SHAPE_TAG:
            newTag = new DefineShapeTag(source, headerLength, dataLength);
            break;
        case PLACE_OBJECT_TAG:
            newTag = new PlaceObjectTag(source, headerLength, dataLength);
            break;
        case REMOVE_OBJECT_TAG:
            newTag = new RemoveObjectTag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_TAG:
            newTag = new DefineBitsTag(source, headerLength, dataLength);
            break;
        case DEFINE_BUTTON_TAG:
            newTag = new DefineButtonTag(source, headerLength, dataLength);
            break;
        case JPEG_TABLES_TAG:
            newTag = new JPEGTablesTag(source, headerLength, dataLength);
            break;
        case SET_BACKGROUND_COLOR_TAG:
            newTag = new SetBackgroundColorTag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_TAG:
            newTag = new DefineFontTag(source, headerLength, dataLength);
            break;
        case DEFINE_TEXT_TAG:
            newTag = new DefineTextTag(source, headerLength, dataLength);
            break;
        case DO_ACTION_TAG:
            newTag = new DoActionTag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_INFO_TAG:
            newTag = new DefineFontInfoTag(source, headerLength, dataLength);
            break;
        case DEFINE_SOUND_TAG:
            newTag = new DefineSoundTag(source, headerLength, dataLength);
            break;
        case START_SOUND_TAG:
            newTag = new StartSoundTag(source, headerLength, dataLength);
            break;
        case DEFINE_BUTTON_SOUND_TAG:
            newTag = new DefineButtonSoundTag(source, headerLength, dataLength);
            break;
        case SOUND_STREAM_HEAD_TAG:
            newTag = new SoundStreamHeadTag(source, headerLength, dataLength);
            break;
        case SOUND_STREAM_BLOCK_TAG:
            newTag = new SoundStreamBlockTag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_LOSSLESS_TAG:
            newTag = new DefineBitsLosslessTag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_JPEG_2_TAG:
            newTag = new DefineBitsJPEG2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_SHAPE_2_TAG:
            newTag = new DefineShape2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_BUTTON_CXFORM_TAG:
            newTag = new DefineButtonCxformTag(source, headerLength, dataLength);
            break;
        case PROTECT_TAG:
            newTag = new ProtectTag(source, headerLength, dataLength);
            break;
        case PLACE_OBJECT_2_TAG:
            newTag = new PlaceObject2Tag(source, headerLength, dataLength);
            break;
        case REMOVE_OBJECT_2_TAG:
            newTag = new RemoveObject2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_SHAPE_3_TAG:
            newTag = new DefineShape3Tag(source, headerLength, dataLength);
            break;
        case DEFINE_TEXT_2_TAG:
            newTag = new DefineText2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_BUTTON_2_TAG:
            newTag = new DefineButton2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_JPEG_3_TAG:
            newTag = new DefineBitsJPEG3Tag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_LOSSLESS_2_TAG:
            newTag = new DefineBitsLossless2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_EDIT_TEXT_TAG:
            newTag = new DefineEditTextTag(source, headerLength, dataLength);
            break;
        case DEFINE_SPRITE_TAG:
            newTag = new DefineSpriteTag(source, headerLength, dataLength, swfFile);
            break;
        case FRAME_LABEL_TAG:
            newTag = new FrameLabelTag(source, headerLength, dataLength);
            break;
        case SOUND_STREAM_HEAD_2_TAG:
            newTag = new SoundStreamHead2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_MORPH_SHAPE_TAG:
            newTag = new DefineMorphShapeTag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_2_TAG:
            newTag = new DefineFont2Tag(source, headerLength, dataLength);
            break;
        case EXPORT_ASSETS_TAG:
            newTag = new ExportAssetsTag(source, headerLength, dataLength);
            break;
        case IMPORT_ASSETS_TAG:
            newTag = new ImportAssetsTag(source, headerLength, dataLength);
            break;
        case ENABLE_DEBUGGER_TAG:
            newTag = new EnableDebuggerTag(source, headerLength, dataLength);
            break;
        case DO_INIT_ACTION_TAG:
            newTag = new DoInitActionTag(source, headerLength, dataLength);
            break;
        case DEFINE_VIDEO_STREAM_TAG:
            newTag = new DefineVideoStreamTag(source, headerLength, dataLength);
            break;
        case VIDEO_FRAME_TAG:
            newTag = new VideoFrameTag(source, headerLength, dataLength, swfFile);
            break;
        case DEFINE_FONT_INFO_2_TAG:
            newTag = new DefineFontInfo2Tag(source, headerLength, dataLength);
            break;
        case ENABLE_DEBUGGER_2_TAG:
            newTag = new EnableDebugger2Tag(source, headerLength, dataLength);
            break;
        case SCRIPT_LIMITS_TAG:
            newTag = new ScriptLimitsTag(source, headerLength, dataLength);
            break;
        case SET_TAB_INDEX_TAG:
            newTag = new SetTabIndexTag(source, headerLength, dataLength);
            break;
        case FILE_ATTRIBUTES_TAG:
            newTag = new FileAttributesTag(source, headerLength, dataLength);
            break;
        case PLACE_OBJECT_3_TAG:
            newTag = new PlaceObject3Tag(source, headerLength, dataLength);
            break;
        case IMPORT_ASSETS_2_TAG:
            newTag = new ImportAssets2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_ALIGN_ZONES_TAG:
            newTag = new DefineFontAlignZonesTag(source, headerLength, dataLength);
            break;
        case CSM_TEXT_SETTINGS_TAG:
            newTag = new CSMTextSettingsTag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_3_TAG:
            newTag = new DefineFont3Tag(source, headerLength, dataLength);
            break;
        case SYMBOL_CLASS_TAG:
            newTag = new SymbolClassTag(source, headerLength, dataLength);
            break;
        case METADATA_TAG:
            newTag = new MetadataTag(source, headerLength, dataLength);
            break;
        case DEFINE_SCALING_GRID_TAG:
            newTag = new DefineScalingGridTag(source, headerLength, dataLength);
            break;
        case DO_ABC_TAG:
            newTag = new DoABCTag(source, headerLength, dataLength);
            break;
        case DEFINE_SHAPE_4_TAG:
            newTag = new DefineShape4Tag(source, headerLength, dataLength);
            break;
        case DEFINE_MORPH_SHAPE_2_TAG:
            newTag = new DefineMorphShape2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_SCENE_AND_FRAME_LABEL_DATA_TAG:
            newTag = new DefineSceneAndFrameLabelDataTag(source, headerLength, dataLength);
            break;
        case DEFINE_BINARY_DATA_TAG:
            newTag = new DefineBinaryDataTag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_NAME_TAG:
            newTag = new DefineFontNameTag(source, headerLength, dataLength);
            break;
        case START_SOUND_2_TAG:
            newTag = new StartSound2Tag(source, headerLength, dataLength);
            break;
        case DEFINE_BITS_JPEG_4_TAG:
            newTag = new DefineBitsJPEG4Tag(source, headerLength, dataLength);
            break;
        case DEFINE_FONT_4_TAG:
            newTag = new DefineFont4Tag(source, headerLength, dataLength);
            break;
        case ENABLE_TELEMETRY_TAG:
            newTag = new EnableTelemetryTag(source, headerLength, dataLength);
            break;
        default:
            newTag = new Tag(source, code, headerLength, dataLength);
            break;
    }
    return newTag;
}

Tag::Tag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength) :
 _rawData(source),
 _valid(true),
 _code(code),
 _headerLength(headerLength),
 _dataLength(dataLength)
{}

void Tag::print() const
{
    std::cout << "Unknown tag valid : " << _valid << std::endl;
    std::cout << "Unknown tag code: " << _code << std::endl;
    std::cout << "Unknown tag dataLength: " << dataLength() << std::endl;
    std::cout << "Unknown tag totalLength: " << totalLength() << std::endl;
}
