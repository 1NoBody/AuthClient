#-------------------------------------------------
#
# Project created by QtCreator 2019-09-10T14:49:29
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AuthClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        wbase.cpp \
    wlogin.cpp \
    whomepage.cpp \
    wauth.cpp \
    wvoucher.cpp \
    wmachinecode.cpp \
    wtextinput.cpp \
    wwait.cpp \
    wauthsuccess.cpp \
    wauthfailure.cpp \
    wreadvoucher.cpp \
    wmessagebox.cpp \
    wresetpsw.cpp \
    jsk_json.cpp \
    toolkit.cpp \
    socket.cpp \
    log.cpp

HEADERS  += wbase.h \
    wlogin.h \
    whomepage.h \
    wauth.h \
    wvoucher.h \
    wmachinecode.h \
    wtextinput.h \
    wwait.h \
    wauthsuccess.h \
    wauthfailure.h \
    wreadvoucher.h \
    wmessagebox.h \
    wresetpsw.h \
    jsk_json.h \
    jsonpack.h \
    toolkit.h \
    socket.h \
    log.h

RESOURCES += \
    image.qrc
