#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T11:51:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    delegate.cpp

HEADERS  += mainwindow.h \
    connection.h \
    delegate.h

FORMS    += mainwindow.ui
