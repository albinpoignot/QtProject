#-------------------------------------------------
#
# Project created by QtCreator 2012-02-13T08:38:12
#
#-------------------------------------------------

include (QMapControl.pri)
QT       += core gui network sql xml

TARGET = projetQt

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    c_webservice.cpp \
    c_poi.cpp

HEADERS  += mainwindow.h \
    c_webservice.h \
    c_poi.h

FORMS    += mainwindow.ui
