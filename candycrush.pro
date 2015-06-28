#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T14:27:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candycrush
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    game.cpp \
    result.cpp \
    candy.cpp \
    explode.cpp \
    stripedh.cpp \
    stripedp.cpp \
    wrapped.cpp

HEADERS  += widget.h \
    game.h \
    result.h \
    candy.h \
    explode.h \
    stripedh.h \
    stripedp.h \
    wrapped.h

FORMS    += widget.ui \
    game.ui \
    result.ui

RESOURCES += \
    pic.qrc
