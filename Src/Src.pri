QT          += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS     += \

SOURCES     += \ 
    $$PWD/main.cpp

RESOURCES   += \
    $$PWD/../Resource/Resource.qrc

include($$PWD/Universal/Universal.pri)
include($$PWD/UI/UI.pri)
include($$PWD/SaveLog/SaveLog.pri)
# include($$PWD/SingleApplication/SingleApplication.pri)