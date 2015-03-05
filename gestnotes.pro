#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T12:21:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestnotes
TEMPLATE = app

CONFIG += c++11
INCLUDEPATH += include

SOURCES += main.cpp\
        src/view/connectionwindow.cpp

HEADERS  += include/view/connectionwindow.h

FORMS    += ui/connectionwindow.ui
