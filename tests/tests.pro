QT += testlib  multimedia multimediawidgets widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app


SOURCES += \
    ../AlarmClock/alarm.cpp \
    ../tests/tst_test_alarm.cpp\
    ../AlarmClock/mainwindow.cpp\


HEADERS += \
    ../AlarmClock/alarm.h\
    ../AlarmClock/mainwindow.h\
    "../AlarmClock/ui_mainwindow.h"\
