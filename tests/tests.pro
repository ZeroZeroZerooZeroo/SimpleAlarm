QT += testlib  multimedia multimediawidgets widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app


SOURCES += \
    ../AlarmClock/alarm.cpp \
    ../tests/tst_test_alarm.cpp

HEADERS += \
    ../AlarmClock/alarm.h
