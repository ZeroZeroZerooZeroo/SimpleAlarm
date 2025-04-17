QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase
HEADERS += alarm.h
SOURCES += alarm.cpp \
           main.cpp \
           mainwindow.cpp
FORMS += mainwindow.ui

# Tests
TEST_SOURCES = tests/test_alarm.cpp
TEST_TARGET = test_alarm
TEMPLATE = app

SOURCES +=  tst_test_alarm.cpp
