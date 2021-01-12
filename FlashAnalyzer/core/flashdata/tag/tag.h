#ifndef TAG_H
#define TAG_H

#include <string>
#include <vector>
#include <memory>

class SWFFile;

class Tag
{
public:
	using tags_t = std::vector<std::unique_ptr<Tag>>;

	static Tag* AddNextTag(const char* source, uint32_t dataMax, tags_t& tags);
	Tag(const char* source, uint32_t code, uint32_t headerLength, uint32_t dataLength);

    inline bool valid() const {return _valid;}
    inline uint32_t code() const {return _code;}
    inline uint32_t headerLength() const {return _headerLength;}
    inline uint32_t dataLength() const {return _dataLength;}
    inline uint32_t totalLength() const {return _headerLength + _dataLength;}

	virtual std::string tagType() const;
	virtual std::string tagDescription() const;

	void setParent(Tag* parent) {_parent = parent;}
	Tag* parent() const {return _parent;}

	const char* data() const {return _rawData;}
	uint32_t dataSize() const {return _dataLength;}

	bool isImage() const;
	bool isVideo() const;
	bool isSound() const;

protected:
    const char*   _rawData;
	bool          _valid;
    
private:
    uint32_t      _code;
    uint32_t      _headerLength;
    uint32_t      _dataLength;
	Tag*          _parent;
};

#define END_TAG                               0  
#define SHOW_FRAME_TAG                        1  
#define DEFINE_SHAPE_TAG                      2  
#define PLACE_OBJECT_TAG                      4  
#define REMOVE_OBJECT_TAG                     5  
#define DEFINE_BITS_TAG                       6  
#define DEFINE_BUTTON_TAG                     7  
#define JPEG_TABLES_TAG                       8  
#define SET_BACKGROUND_COLOR_TAG              9  
#define DEFINE_FONT_TAG                       10 
#define DEFINE_TEXT_TAG                       11 
#define DO_ACTION_TAG                         12 
#define DEFINE_FONT_INFO_TAG                  13 
#define DEFINE_SOUND_TAG                      14 
#define START_SOUND_TAG                       15 
#define DEFINE_BUTTON_SOUND_TAG               17 
#define SOUND_STREAM_HEAD_TAG                 18 
#define SOUND_STREAM_BLOCK_TAG                19 
#define DEFINE_BITS_LOSSLESS_TAG              20 
#define DEFINE_BITS_JPEG_2_TAG                21 
#define DEFINE_SHAPE_2_TAG                    22 
#define DEFINE_BUTTON_CXFORM_TAG              23 
#define PROTECT_TAG                           24 
#define PLACE_OBJECT_2_TAG                    26 
#define REMOVE_OBJECT_2_TAG                   28 
#define DEFINE_SHAPE_3_TAG                    32 
#define DEFINE_TEXT_2_TAG                     33 
#define DEFINE_BUTTON_2_TAG                   34 
#define DEFINE_BITS_JPEG_3_TAG                35 
#define DEFINE_BITS_LOSSLESS_2_TAG            36 
#define DEFINE_EDIT_TEXT_TAG                  37 
#define DEFINE_SPRITE_TAG                     39 
#define FRAME_LABEL_TAG                       43 
#define SOUND_STREAM_HEAD_2_TAG               45 
#define DEFINE_MORPH_SHAPE_TAG                46 
#define DEFINE_FONT_2_TAG                     48 
#define EXPORT_ASSETS_TAG                     56 
#define IMPORT_ASSETS_TAG                     57 
#define ENABLE_DEBUGGER_TAG                   58 
#define DO_INIT_ACTION_TAG                    59 
#define DEFINE_VIDEO_STREAM_TAG               60 
#define VIDEO_FRAME_TAG                       61 
#define DEFINE_FONT_INFO_2_TAG                62 
#define ENABLE_DEBUGGER_2_TAG                 64 
#define SCRIPT_LIMITS_TAG                     65 
#define SET_TAB_INDEX_TAG                     66 
#define FILE_ATTRIBUTES_TAG                   69 
#define PLACE_OBJECT_3_TAG                    70 
#define IMPORT_ASSETS_2_TAG                   71 
#define DEFINE_FONT_ALIGN_ZONES_TAG           73 
#define CSM_TEXT_SETTINGS_TAG                 74 
#define DEFINE_FONT_3_TAG                     75 
#define SYMBOL_CLASS_TAG                      76 
#define METADATA_TAG                          77 
#define DEFINE_SCALING_GRID_TAG               78 
#define DO_ABC_TAG                            82 
#define DEFINE_SHAPE_4_TAG                    83 
#define DEFINE_MORPH_SHAPE_2_TAG              84 
#define DEFINE_SCENE_AND_FRAME_LABEL_DATA_TAG 86 
#define DEFINE_BINARY_DATA_TAG                87 
#define DEFINE_FONT_NAME_TAG                  88 
#define START_SOUND_2_TAG                     89 
#define DEFINE_BITS_JPEG_4_TAG                90 
#define DEFINE_FONT_4_TAG                     91 
#define ENABLE_TELEMETRY_TAG                  93 

#endif // TAG_H
