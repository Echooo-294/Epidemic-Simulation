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
    feature_resident/resident.cpp \
    feature_resident/vaccination.cpp \
    feature_space/door.cpp \
    feature_virus/infectionProbability.cpp \
    feature_simulation/fullyOpen.cpp \
    feature_timeAndStatistic/timeRelevant.cpp \
    feature_virus/treatment.cpp \
    feature_virus/virus.cpp \
    feature_space/space.cpp \
    feature_virus/virusGrowth.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    feature_resident/resident.h \
    feature_space/door.h \
    feature_virus/virus.h \
    feature_space/space.h \
    widget.h\

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
