#-------------------------------------------------
#
# Project created by QtCreator 2022-11-14T20:18:10
#
#-------------------------------------------------

QT       += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

LIBS     += -lgtest -lpthread -lgcov

# TARGET = First-test
# TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


QMAKE_CXXFLAGS += --coverage
CONFIG += c++17
QMAKE_CXXFLAGS_WARN_OFF += -Wunused-value
QMAKE_CXXFLAGS_WARN_ON -= -Wall

SOURCES += \
    s21_3DViewer_V2-1_test.cc \
    s21_afines.cc \
    s21_matrix_oop.cc \
    s21_model.cc \

HEADERS += \
    s21_afines.h \
    s21_matrix_oop.h \
    s21_model.h \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

