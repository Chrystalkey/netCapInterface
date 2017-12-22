#-------------------------------------------------
#
# Project created by QtCreator 2017-12-03T21:39:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netCapInterface
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


SOURCES += \
        main.cpp \
        statistics.cpp \
    device.cpp \
    headerstructs.cpp \
    capturemgr.cpp \
    networkdevice.cpp \
    spoofingmgr.cpp

HEADERS += \
        statistics.h \
    device.h \
    headerstructs.h \
    global.h \
    capturemgr.h \
    networkdevice.h \
    spoofingmgr.h

#### wnpcap ####
win32: LIBS += -LD:/dev/WpdPack/Lib/ -lwpcap

INCLUDEPATH += D:/dev/WpdPack/Include
DEPENDPATH += D:/dev/WpdPack/Include

win32:!win32-g++: PRE_TARGETDEPS += D:/dev/WpdPack/Lib/wpcap.lib
else:win32-g++: PRE_TARGETDEPS += D:/dev/WpdPack/Lib/libwpcap.a


#### libnet ####
win32: LIBS += -L$$PWD/../../../../libnet/lib/ -lnet
INCLUDEPATH += $$PWD/../../../../libnet/include
DEPENDPATH += $$PWD/../../../../libnet/include
INCLUDEPATH += $$PWD/../../../../libnet/lib/include
DEPENDPATH += $$PWD/../../../../libnet/lib/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../../libnet/lib/net.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../../../libnet/lib/libnet.a

