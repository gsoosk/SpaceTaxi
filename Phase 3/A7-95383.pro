#-------------------------------------------------
#
# Project created by QtCreator 2017-05-21T21:11:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A7-95383
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
        login.cpp \
    client_socket.cpp \
    Functions.cpp \
    tools.cpp \
    connection.cpp \
    Register.cpp \
    panel.cpp \
    charge_account.cpp \
    rate.cpp \
    request.cpp

HEADERS  += login.h \
    client_socket.h \
    Functions.h \
    tools.h \
    network_exception.h \
    connection.h \
    Register.h \
    panel.h \
    charge_account.h \
    rate.h \
    request.h

FORMS    += login.ui \
    register.ui \
    panel.ui \
    chargeaccount.ui \
    rate.ui \
    request.ui

RESOURCES += \
    images.qrc
