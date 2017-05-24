#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T16:25:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plotTest
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    plot.cpp \
    curvedata.cpp \
    signaldata.cpp

HEADERS  += widget.h \
    plot.h \
    curvedata.h \
    signaldata.h

FORMS    += widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qwt-6.1.3/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qwt-6.1.3/lib/ -lqwtd
else:unix:!macx: LIBS += -L$$PWD/../qwt-6.1.3/lib/ -lqwt

INCLUDEPATH += $$PWD/../qwt-6.1.3/src
DEPENDPATH += $$PWD/../qwt-6.1.3/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../qwt-6.1.3/lib/libqwt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../qwt-6.1.3/lib/libqwtd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../qwt-6.1.3/lib/qwt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../qwt-6.1.3/lib/qwtd.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../qwt-6.1.3/lib/libqwt.a
