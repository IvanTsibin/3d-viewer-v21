#QT       += core gui widgets opengl openglwidgets
QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../affin.c \
    ../parser.c \
    geometryengine.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    src/3rdParty/giflib/dgif_lib.c \
    src/3rdParty/giflib/egif_lib.c \
    src/3rdParty/giflib/gif_err.c \
    src/3rdParty/giflib/gif_font.c \
    src/3rdParty/giflib/gif_hash.c \
    src/3rdParty/giflib/gifalloc.c \
    src/3rdParty/giflib/quantize.c \
    src/gifimage/doc/snippets/doc_src_qtgifimage.cpp \
    src/gifimage/qgifimage.cpp

HEADERS += \
    ../parser.h \
    geometryengine.h \
    mainwidget.h \
    mainwindow.h \
    src/3rdParty/giflib/gif_hash.h \
    src/3rdParty/giflib/gif_lib.h \
    src/3rdParty/giflib/gif_lib_private.h \
    src/gifimage/qgifglobal.h \
    src/gifimage/qgifimage.h \
    src/gifimage/qgifimage_p.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
include(src/3rdparty/qtgifimage/src/gifimage/qtgifimage.pri)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shaders.qrc \
    textures.qrc

DISTFILES += \
    cube.png \
    fshader.glsl \
    src/3rdParty/giflib.pri \
    src/3rdParty/giflib/AUTHORS \
    src/3rdParty/giflib/COPYING \
    src/3rdParty/giflib/README \
    src/gifimage/doc/qtgifimage.qdocconf \
    src/gifimage/doc/src/examples.qdoc \
    src/gifimage/doc/src/index.qdoc \
    src/gifimage/doc/src/qtgifimage.qdoc \
    src/gifimage/doc/src/usage.qdoc \
    src/gifimage/qtgifimage.pri \
    vshader.glsl

SUBDIRS += \
    src/gifimage/doc/snippets/doc_src_qtgifimage.pro \
    src/gifimage/gifimage.pro \
    src/src.pro
