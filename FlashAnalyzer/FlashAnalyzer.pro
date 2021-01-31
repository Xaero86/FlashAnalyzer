QT       += core gui
# QT5
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    flashdata/controltag.cpp \
	flashdata/datatypes.cpp \
	flashdata/definitiontag.cpp \
	flashdata/swffile.cpp \
	flashdata/tag/csmtextsettingstag.cpp \
	flashdata/tag/definebinarydatatag.cpp \
	flashdata/tag/definebitsjpeg2tag.cpp \
	flashdata/tag/definebitsjpeg3tag.cpp \
	flashdata/tag/definebitsjpeg4tag.cpp \
	flashdata/tag/definebitslossless2tag.cpp \
	flashdata/tag/definebitslosslesstag.cpp \
	flashdata/tag/definebitstag.cpp \
	flashdata/tag/definebutton2tag.cpp \
	flashdata/tag/definebuttoncxformtag.cpp \
	flashdata/tag/definebuttonsoundtag.cpp \
	flashdata/tag/definebuttontag.cpp \
	flashdata/tag/defineedittexttag.cpp \
	flashdata/tag/definefont2tag.cpp \
	flashdata/tag/definefont3tag.cpp \
	flashdata/tag/definefont4tag.cpp \
	flashdata/tag/definefontalignzonestag.cpp \
	flashdata/tag/definefontinfo2tag.cpp \
	flashdata/tag/definefontinfotag.cpp \
	flashdata/tag/definefontnametag.cpp \
	flashdata/tag/definefonttag.cpp \
	flashdata/tag/definemorphshape2tag.cpp \
	flashdata/tag/definemorphshapetag.cpp \
	flashdata/tag/definescalinggridtag.cpp \
	flashdata/tag/definesceneandframelabeldatatag.cpp \
	flashdata/tag/defineshape2tag.cpp \
	flashdata/tag/defineshape3tag.cpp \
	flashdata/tag/defineshape4tag.cpp \
	flashdata/tag/defineshapetag.cpp \
	flashdata/tag/definesoundtag.cpp \
	flashdata/tag/definespritetag.cpp \
	flashdata/tag/definetext2tag.cpp \
	flashdata/tag/definetexttag.cpp \
	flashdata/tag/definevideostreamtag.cpp \
	flashdata/tag/doabctag.cpp \
	flashdata/tag/doactiontag.cpp \
	flashdata/tag/doinitactiontag.cpp \
	flashdata/tag/enabledebugger2tag.cpp \
	flashdata/tag/enabledebuggertag.cpp \
	flashdata/tag/enabletelemetrytag.cpp \
	flashdata/tag/endtag.cpp \
	flashdata/tag/exportassetstag.cpp \
	flashdata/tag/fileattributestag.cpp \
	flashdata/tag/framelabeltag.cpp \
	flashdata/tag/importassets2tag.cpp \
	flashdata/tag/importassetstag.cpp \
	flashdata/tag/jpegtablestag.cpp \
	flashdata/tag/metadatatag.cpp \
	flashdata/tag/placeobject2tag.cpp \
	flashdata/tag/placeobject3tag.cpp \
	flashdata/tag/placeobjecttag.cpp \
	flashdata/tag/protecttag.cpp \
	flashdata/tag/removeobject2tag.cpp \
	flashdata/tag/removeobjecttag.cpp \
	flashdata/tag/scriptlimitstag.cpp \
	flashdata/tag/setbackgroundcolortag.cpp \
	flashdata/tag/settabindextag.cpp \
	flashdata/tag/showframetag.cpp \
	flashdata/tag/soundstreamblocktag.cpp \
	flashdata/tag/soundstreamhead2tag.cpp \
	flashdata/tag/soundstreamheadtag.cpp \
	flashdata/tag/startsound2tag.cpp \
	flashdata/tag/startsoundtag.cpp \
	flashdata/tag/symbolclasstag.cpp \
	flashdata/tag/videoframetag.cpp \
	flashdata/tag.cpp \
	flashdata/tools.cpp \
    main.cpp \
    ui/extractablemodel.cpp \
    ui/extractableview.cpp \
    ui/imagepreview.cpp \
	ui/mainwindow.cpp \
	ui/loggerconsole.cpp \
    ui/rawdatawidget.cpp \
    ui/tagsmodel.cpp \
    ui/videopreview.cpp

HEADERS += \
    flashdata/controltag.h \
	flashdata/datatypes.h \
	flashdata/definitiontag.h \
	flashdata/extractabletag.h \
	flashdata/imagetag.h \
	flashdata/swffile.h \
	flashdata/tag/csmtextsettingstag.h \
	flashdata/tag/definebinarydatatag.h \
	flashdata/tag/definebitsjpeg2tag.h \
	flashdata/tag/definebitsjpeg3tag.h \
	flashdata/tag/definebitsjpeg4tag.h \
	flashdata/tag/definebitslossless2tag.h \
	flashdata/tag/definebitslosslesstag.h \
	flashdata/tag/definebitstag.h \
	flashdata/tag/definebutton2tag.h \
	flashdata/tag/definebuttoncxformtag.h \
	flashdata/tag/definebuttonsoundtag.h \
	flashdata/tag/definebuttontag.h \
	flashdata/tag/defineedittexttag.h \
	flashdata/tag/definefont2tag.h \
	flashdata/tag/definefont3tag.h \
	flashdata/tag/definefont4tag.h \
	flashdata/tag/definefontalignzonestag.h \
	flashdata/tag/definefontinfo2tag.h \
	flashdata/tag/definefontinfotag.h \
	flashdata/tag/definefontnametag.h \
	flashdata/tag/definefonttag.h \
	flashdata/tag/definemorphshape2tag.h \
	flashdata/tag/definemorphshapetag.h \
	flashdata/tag/definescalinggridtag.h \
	flashdata/tag/definesceneandframelabeldatatag.h \
	flashdata/tag/defineshape2tag.h \
	flashdata/tag/defineshape3tag.h \
	flashdata/tag/defineshape4tag.h \
	flashdata/tag/defineshapetag.h \
	flashdata/tag/definesoundtag.h \
	flashdata/tag/definespritetag.h \
	flashdata/tag/definetext2tag.h \
	flashdata/tag/definetexttag.h \
	flashdata/tag/definevideostreamtag.h \
	flashdata/tag/doabctag.h \
	flashdata/tag/doactiontag.h \
	flashdata/tag/doinitactiontag.h \
	flashdata/tag/enabledebugger2tag.h \
	flashdata/tag/enabledebuggertag.h \
	flashdata/tag/enabletelemetrytag.h \
	flashdata/tag/endtag.h \
	flashdata/tag/exportassetstag.h \
	flashdata/tag/fileattributestag.h \
	flashdata/tag/framelabeltag.h \
	flashdata/tag/importassets2tag.h \
	flashdata/tag/importassetstag.h \
	flashdata/tag/jpegtablestag.h \
	flashdata/tag/metadatatag.h \
	flashdata/tag/placeobject2tag.h \
	flashdata/tag/placeobject3tag.h \
	flashdata/tag/placeobjecttag.h \
	flashdata/tag/protecttag.h \
	flashdata/tag/removeobject2tag.h \
	flashdata/tag/removeobjecttag.h \
	flashdata/tag/scriptlimitstag.h \
	flashdata/tag/setbackgroundcolortag.h \
	flashdata/tag/settabindextag.h \
	flashdata/tag/showframetag.h \
	flashdata/tag/soundstreamblocktag.h \
	flashdata/tag/soundstreamhead2tag.h \
	flashdata/tag/soundstreamheadtag.h \
	flashdata/tag/startsound2tag.h \
	flashdata/tag/startsoundtag.h \
	flashdata/tag/symbolclasstag.h \
	flashdata/tag/videoframetag.h \
	flashdata/tag.h \
	flashdata/tools.h \
    ui/extractablemodel.h \
    ui/extractableview.h \
    ui/imagepreview.h \
    ui/mainwindow.h \
	ui/loggerconsole.h \
    ui/rawdatawidget.h \
    ui/tagsmodel.h \
    ui/videopreview.h

INCLUDEPATH = $$PWD/ui $$PWD/flashdata $$PWD/flashdata/tag/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
