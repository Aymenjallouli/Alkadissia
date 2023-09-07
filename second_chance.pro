QT       += core gui sql charts serialport
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    createelevewindow.cpp \
    createwindow.cpp \
    deleteelevewindow.cpp \
    deletewindow.cpp \
    elevemainwindow.cpp \
    eleves.cpp \
    enseignant.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    readelevewindow.cpp \
    readwindow.cpp \
    updateelevewindow.cpp \
    updatewindow.cpp

HEADERS += \
    connection.h \
    createelevewindow.h \
    createwindow.h \
    deleteelevewindow.h \
    deletewindow.h \
    elevemainwindow.h \
    eleves.h \
    enseignant.h \
    login.h \
    mainwindow.h \
    readelevewindow.h \
    readwindow.h \
    updateelevewindow.h \
    updatewindow.h

FORMS += \
    createelevewindow.ui \
    createwindow.ui \
    deleteelevewindow.ui \
    deletewindow.ui \
    elevemainwindow.ui \
    login.ui \
    mainwindow.ui \
    readelevewindow.ui \
    readwindow.ui \
    updateelevewindow.ui \
    updatewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Downloads/330143539_1679728879096029_248540937279730877_n.jpg
