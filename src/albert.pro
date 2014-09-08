#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T00:53:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = albert
TEMPLATE = app



INCLUDEPATH += frontend/ \
	backend
VPATH += frontend/ \
	backend

HEADERS  +=	backend/abstractindexprovider.h \
	backend/abstractserviceprovider.h \
	backend/albertengine.h \
	albert.h \
	frontend/proposallistdelegate.h \
	frontend/proposallistmodel.h \
	frontend/proposallistview.h \
	frontend/xhotkeymanager.h \
	backend/filesystemindex/filesystemindex.h \
	frontend/inputline.h \
	backend/settings.h

SOURCES += main.cpp \
	backend/abstractindexprovider.cpp \
	backend/abstractserviceprovider.cpp \
	backend/albertengine.cpp \
	albert.cpp \
	frontend/proposallistdelegate.cpp \
	frontend/proposallistmodel.cpp \
	frontend/proposallistview.cpp \
	frontend/xhotkeymanager.cpp \
	backend/filesystemindex/filesystemindex.cpp \
	frontend/inputline.cpp \
	backend/settings.cpp

RESOURCES += albert.qrc

CONFIG += c++11

LIBS += -lX11 -lboost_system -lboost_filesystem -lboost_timer

#DEFINES += QT_NO_CAST_FROM_ASCII \
			 #QT_NO_CAST_TO_ASCII

QMAKE_CXXFLAGS_WARN_ON += -Werror
