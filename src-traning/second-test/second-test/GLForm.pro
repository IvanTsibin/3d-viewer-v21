QT =core gui opengl
TARGET = GlForm
TEMPLATE = app
LIBS += -L/usr/local/lib -lGLU
SOURCES  = main.cpp\
        scenegl.cpp
HEADERS =\
        scenegl.h
