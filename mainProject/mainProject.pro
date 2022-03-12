QT       += core gui

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
    D:/qt doc/untitled1/q.cpp \
    feature_resident/resident.cpp \
    feature_virus/feature_virus.cpp \
    feature_virus/virus.cpp \
    feature_virus/virus.cpp \
    feature_space/space.cpp \
    feature_virus/virusGrowth.cpp \
    main.cpp \
    v.cpp \
    widget.cpp

HEADERS += \
    D:/qt doc/untitled1/q.h \
    feature_resident/resident.h \
<<<<<<< HEAD
    feature_virus/feature_virus.h \
    feature_virus/virus.h \
    feature_virus/virus.h \
=======
    feature_space/space.h \
>>>>>>> 2e8f23cb1e56e8530a33266e7c387777a9c92676
    widget.h\

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
