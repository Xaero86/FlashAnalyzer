QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/flashdata/datatypes.cpp \
    core/flashdata/swffile.cpp \
    core/flashdata/tag/controltag.cpp \
    core/flashdata/tag/csmtextsettingstag.cpp \
    core/flashdata/tag/definebinarydatatag.cpp \
    core/flashdata/tag/definebitsjpeg2tag.cpp \
    core/flashdata/tag/definebitsjpeg3tag.cpp \
    core/flashdata/tag/definebitsjpeg4tag.cpp \
    core/flashdata/tag/definebitslossless2tag.cpp \
    core/flashdata/tag/definebitslosslesstag.cpp \
    core/flashdata/tag/definebitstag.cpp \
    core/flashdata/tag/definebutton2tag.cpp \
    core/flashdata/tag/definebuttoncxformtag.cpp \
    core/flashdata/tag/definebuttonsoundtag.cpp \
    core/flashdata/tag/definebuttontag.cpp \
    core/flashdata/tag/defineedittexttag.cpp \
    core/flashdata/tag/definefont2tag.cpp \
    core/flashdata/tag/definefont3tag.cpp \
    core/flashdata/tag/definefont4tag.cpp \
    core/flashdata/tag/definefontalignzonestag.cpp \
    core/flashdata/tag/definefontinfo2tag.cpp \
    core/flashdata/tag/definefontinfotag.cpp \
    core/flashdata/tag/definefontnametag.cpp \
    core/flashdata/tag/definefonttag.cpp \
    core/flashdata/tag/definemorphshape2tag.cpp \
    core/flashdata/tag/definemorphshapetag.cpp \
    core/flashdata/tag/definescalinggridtag.cpp \
    core/flashdata/tag/definesceneandframelabeldatatag.cpp \
    core/flashdata/tag/defineshape2tag.cpp \
    core/flashdata/tag/defineshape3tag.cpp \
    core/flashdata/tag/defineshape4tag.cpp \
    core/flashdata/tag/defineshapetag.cpp \
    core/flashdata/tag/definesoundtag.cpp \
    core/flashdata/tag/definespritetag.cpp \
    core/flashdata/tag/definetext2tag.cpp \
    core/flashdata/tag/definetexttag.cpp \
    core/flashdata/tag/definevideostreamtag.cpp \
    core/flashdata/tag/definitiontag.cpp \
    core/flashdata/tag/doabctag.cpp \
    core/flashdata/tag/doactiontag.cpp \
    core/flashdata/tag/doinitactiontag.cpp \
    core/flashdata/tag/enabledebugger2tag.cpp \
    core/flashdata/tag/enabledebuggertag.cpp \
    core/flashdata/tag/enabletelemetrytag.cpp \
    core/flashdata/tag/endtag.cpp \
    core/flashdata/tag/exportassetstag.cpp \
    core/flashdata/tag/fileattributestag.cpp \
    core/flashdata/tag/framelabeltag.cpp \
    core/flashdata/tag/importassets2tag.cpp \
    core/flashdata/tag/importassetstag.cpp \
    core/flashdata/tag/jpegtablestag.cpp \
    core/flashdata/tag/metadatatag.cpp \
    core/flashdata/tag/placeobject2tag.cpp \
    core/flashdata/tag/placeobject3tag.cpp \
    core/flashdata/tag/placeobjecttag.cpp \
    core/flashdata/tag/protecttag.cpp \
    core/flashdata/tag/removeobject2tag.cpp \
    core/flashdata/tag/removeobjecttag.cpp \
    core/flashdata/tag/scriptlimitstag.cpp \
    core/flashdata/tag/setbackgroundcolortag.cpp \
    core/flashdata/tag/settabindextag.cpp \
    core/flashdata/tag/showframetag.cpp \
    core/flashdata/tag/soundstreamblocktag.cpp \
    core/flashdata/tag/soundstreamhead2tag.cpp \
    core/flashdata/tag/soundstreamheadtag.cpp \
    core/flashdata/tag/startsound2tag.cpp \
    core/flashdata/tag/startsoundtag.cpp \
    core/flashdata/tag/symbolclasstag.cpp \
    core/flashdata/tag/tag.cpp \
    core/flashdata/tag/videoframetag.cpp \
    core/flashdata/tools.cpp \
    main.cpp \
	ui/mainwindow.cpp \
	ui/loggerconsole.cpp

HEADERS += \
    core/flashdata/datatypes.h \
    core/flashdata/swffile.h \
    core/flashdata/tag/controltag.h \
    core/flashdata/tag/csmtextsettingstag.h \
    core/flashdata/tag/definebinarydatatag.h \
    core/flashdata/tag/definebitsjpeg2tag.h \
    core/flashdata/tag/definebitsjpeg3tag.h \
    core/flashdata/tag/definebitsjpeg4tag.h \
    core/flashdata/tag/definebitslossless2tag.h \
    core/flashdata/tag/definebitslosslesstag.h \
    core/flashdata/tag/definebitstag.h \
    core/flashdata/tag/definebutton2tag.h \
    core/flashdata/tag/definebuttoncxformtag.h \
    core/flashdata/tag/definebuttonsoundtag.h \
    core/flashdata/tag/definebuttontag.h \
    core/flashdata/tag/defineedittexttag.h \
    core/flashdata/tag/definefont2tag.h \
    core/flashdata/tag/definefont3tag.h \
    core/flashdata/tag/definefont4tag.h \
    core/flashdata/tag/definefontalignzonestag.h \
    core/flashdata/tag/definefontinfo2tag.h \
    core/flashdata/tag/definefontinfotag.h \
    core/flashdata/tag/definefontnametag.h \
    core/flashdata/tag/definefonttag.h \
    core/flashdata/tag/definemorphshape2tag.h \
    core/flashdata/tag/definemorphshapetag.h \
    core/flashdata/tag/definescalinggridtag.h \
    core/flashdata/tag/definesceneandframelabeldatatag.h \
    core/flashdata/tag/defineshape2tag.h \
    core/flashdata/tag/defineshape3tag.h \
    core/flashdata/tag/defineshape4tag.h \
    core/flashdata/tag/defineshapetag.h \
    core/flashdata/tag/definesoundtag.h \
    core/flashdata/tag/definespritetag.h \
    core/flashdata/tag/definetext2tag.h \
    core/flashdata/tag/definetexttag.h \
    core/flashdata/tag/definevideostreamtag.h \
    core/flashdata/tag/definitiontag.h \
    core/flashdata/tag/doabctag.h \
    core/flashdata/tag/doactiontag.h \
    core/flashdata/tag/doinitactiontag.h \
    core/flashdata/tag/enabledebugger2tag.h \
    core/flashdata/tag/enabledebuggertag.h \
    core/flashdata/tag/enabletelemetrytag.h \
    core/flashdata/tag/endtag.h \
    core/flashdata/tag/exportassetstag.h \
    core/flashdata/tag/fileattributestag.h \
    core/flashdata/tag/framelabeltag.h \
    core/flashdata/tag/imagetag.h \
    core/flashdata/tag/importassets2tag.h \
    core/flashdata/tag/importassetstag.h \
    core/flashdata/tag/jpegtablestag.h \
    core/flashdata/tag/metadatatag.h \
    core/flashdata/tag/placeobject2tag.h \
    core/flashdata/tag/placeobject3tag.h \
    core/flashdata/tag/placeobjecttag.h \
    core/flashdata/tag/protecttag.h \
    core/flashdata/tag/removeobject2tag.h \
    core/flashdata/tag/removeobjecttag.h \
    core/flashdata/tag/scriptlimitstag.h \
    core/flashdata/tag/setbackgroundcolortag.h \
    core/flashdata/tag/settabindextag.h \
    core/flashdata/tag/showframetag.h \
    core/flashdata/tag/soundstreamblocktag.h \
    core/flashdata/tag/soundstreamhead2tag.h \
    core/flashdata/tag/soundstreamheadtag.h \
    core/flashdata/tag/startsound2tag.h \
    core/flashdata/tag/startsoundtag.h \
    core/flashdata/tag/symbolclasstag.h \
    core/flashdata/tag/tag.h \
    core/flashdata/tag/videoframetag.h \
    core/flashdata/tools.h \
    ui/mainwindow.h \
	ui/loggerconsole.h

INCLUDEPATH = $$PWD/ui $$PWD/core $$PWD/core/flashdata $$PWD/core/flashdata/tag/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
