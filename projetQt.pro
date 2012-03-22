#-------------------------------------------------
#
# Project created by QtCreator 2012-02-13T08:38:12
#
#-------------------------------------------------

include (QMapControl.pri)
QT       += core gui network sql xml

TARGET = projetQt

TEMPLATE = app

CONFIG  += qtestlib

SOURCES += main.cpp\
        mainwindow.cpp \
    c_webservice.cpp \
    c_poi.cpp \
    accueil.cpp \
    c_qdbc.cpp \
    c_details.cpp \
    settings.cpp \
    c_modeemploi.cpp \
    testclasse.cpp

HEADERS  += mainwindow.h \
    c_webservice.h \
    c_poi.h \
    accueil.h \
    c_qdbc.h \
    c_details.h \
    settings.h \
    c_modeemploi.h \
    testclasse.h

FORMS    += mainwindow.ui \
    accueil.ui \
    c_details.ui \
    settings.ui \
    c_modeemploi.ui
