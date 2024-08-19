QT          += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

DEFINES     += VABSTRACTWIDGET_MODULE

HEADERS     += \
    $$PWD/VAbstractWidget \
    $$PWD/VAbstractWidget.h

SOURCES     += \
    $$PWD/VAbstractWidget.cpp

RESOURCES   += \
    $$PWD/Resources/VAbstractWidget.qrc
