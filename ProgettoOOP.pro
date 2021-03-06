#-------------------------------------------------
#
# Project created by QtCreator 2020-03-25T10:42:20
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProgettoOOP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        modello/audiolibro.cpp \
        modello/container.cpp \
        modello/fileaudio.cpp \
        modello/film.cpp \
        modello/libro.cpp \
        modello/librodigitale.cpp \
        modello/mediaitem.cpp \
        modello/modello.cpp \
        modello/musica.cpp \
        modello/xml.cpp \
        vista/about.cpp \
        vista/duratatotale.cpp \
        vista/inserimento.cpp \
        vista/mainwindow.cpp \
        vista/modifica.cpp \
        vista/ricerca.cpp \
        vista/sviluppo.cpp

HEADERS += \
        modello/audiolibro.h \
        modello/container.h \
        modello/fileaudio.h \
        modello/film.h \
        modello/libro.h \
        modello/librodigitale.h \
        modello/mediaitem.h \
        modello/modello.h \
        modello/musica.h \
        modello/xml.h \
        vista/about.h \
        vista/duratatotale.h \
        vista/inserimento.h \
        vista/mainwindow.h \
        vista/modifica.h \
        vista/ricerca.h \
        vista/sviluppo.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    risorse.qrc
