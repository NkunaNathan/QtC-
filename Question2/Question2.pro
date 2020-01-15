#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T16:36:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Question2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    company.cpp \
    profit.cpp \
    nonprofit.cpp \
    companylist.cpp \
    companywriter.cpp

HEADERS  += mainwindow.h \
    company.h \
    profit.h \
    nonprofit.h \
    companylist.h \
    companywriter.h

FORMS    += mainwindow.ui
