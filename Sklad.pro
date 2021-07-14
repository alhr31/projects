#-------------------------------------------------
#
# Project created by QtCreator 2018-11-27T22:26:49
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sklad
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
        mainwindow.cpp \
    postavkiform.cpp \
    prodajiform.cpp \
    tovariform.cpp \
    addtovarform.cpp \
    deltovarform.cpp \
    addpostavkiform.cpp \
    postavshikform.cpp \
    addpostform.cpp \
    delpostform.cpp \
    addprodajiform.cpp \
    klientiform.cpp \
    addklientform.cpp \
    delklientform.cpp \
    pechatprform.cpp \
    pechatpform.cpp

HEADERS += \
        mainwindow.h \
    postavkiform.h \
    prodajiform.h \
    tovariform.h \
    addtovarform.h \
    deltovarform.h \
    addpostavkiform.h \
    postavshikform.h \
    addpostform.h \
    delpostform.h \
    addprodajiform.h \
    klientiform.h \
    addklientform.h \
    delklientform.h \
    pechatprform.h \
    pechatpform.h

FORMS += \
        mainwindow.ui \
    postavkiform.ui \
    prodajiform.ui \
    tovariform.ui \
    addtovarform.ui \
    deltovarform.ui \
    addpostavkiform.ui \
    postavshikform.ui \
    addpostform.ui \
    delpostform.ui \
    addprodajiform.ui \
    klientiform.ui \
    addklientform.ui \
    delklientform.ui \
    pechatprform.ui \
    pechatpform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

