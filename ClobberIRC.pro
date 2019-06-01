#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T10:13:21
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClobberIRC
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

CONFIG += c++11

SOURCES += \
		src/application.cpp \
		src/appwindow.cpp

HEADERS += \
		src/appwindow.h \
		src/messageformatter.h

FORMS += \
		src/appwindow.ui

##################################################
# Communi stuff

#DEFINES += IRC_NAMESPACE=communi
INCLUDEPATH += libcommuni/include
include(libcommuni/src/src.pri)

##################################################

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	.gitignore \
	LICENSE \
	README.md
