#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T12:21:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestnotes
TEMPLATE = app

CONFIG += c++11
INCLUDEPATH += include

SOURCES += main.cpp\
    src/view/connectionwindow.cpp \
    src/model/actor.cpp \
    src/model/administrator.cpp \
    src/model/entity.cpp \
    src/model/repository.cpp \
    src/model/administrator_repository.cpp

HEADERS  += include/view/connectionwindow.h \
    include/model/actor.h \
    include/model/administrator.h \
    include/model/entity.h \
    include/model/repository.h \
    include/model/administrator_repository.h

FORMS    += ui/connectionwindow.ui
