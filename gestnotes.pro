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
    src/model/administrator_repository.cpp \
    src/model/student.cpp \
    src/model/student_repository.cpp \
    src/model/professor.cpp \
    src/model/professor_repository.cpp \
    src/model/phone.cpp \
    src/model/address.cpp \
    src/model/coordinates.cpp \
    src/model/contact.cpp \
    src/model/coordinates_repository.cpp \
    src/model/phone_repository.cpp \
    src/model/contact_repository.cpp

HEADERS  += include/view/connectionwindow.h \
    include/model/actor.h \
    include/model/administrator.h \
    include/model/entity.h \
    include/model/repository.h \
    include/model/administrator_repository.h \
    include/model/student.h \
    include/model/student_repository.h \
    include/model/professor.h \
    include/model/professor_repository.h \
    include/model/phone.h \
    include/model/address.h \
    include/model/coordinates.h \
    include/model/contact.h \
    include/model/coordinates_repository.h \
    include/model/phone_repository.h \
    include/model/contact_repository.h

FORMS    += ui/connectionwindow.ui \
    ui/interface.ui \
    ui/mainwindow.ui
