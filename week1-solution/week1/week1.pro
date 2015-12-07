QT += sql
QT += core
QT -= gui

TARGET = week1
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    models/computer.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    utilities/utils.cpp \
    utilities/scientistcomparator.cpp \
    utilities/computercomparator.cpp \
    Database/database.cpp \
    utilities/computercomparator.cpp

HEADERS += \
    models/scientist.h \
    models/computer.h \
    repositories/scientistrepository.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    ui/consoleui.h \
    utilities/scientistcomparator.h \
    utilities/computercomparator.h \
    Database/database.h \
    utilities/computercomparator.h

