#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T23:45:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particle_System
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    canvas.cpp \
    particle.cpp \
    explosion.cpp

HEADERS  += widget.h \
    canvas.h \
    particle.h \
    explosion.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc
