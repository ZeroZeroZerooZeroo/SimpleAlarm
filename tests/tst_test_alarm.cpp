#include <QCoreApplication>
#include <QtTest>
#include "../AlarmClock/alarm.h"
#include "../AlarmClock/alarm.cpp"
// add necessary includes here

class TestAlarm : public QObject
{
    Q_OBJECT

public:
    TestAlarm();
    ~TestAlarm();


private slots:
    void test_case1();
    void testAlarmTimeSetting();
};

TestAlarm::TestAlarm() {}

TestAlarm::~TestAlarm() {}

void TestAlarm::test_case1() {}

void TestAlarm::testAlarmTimeSetting()
{
    Alarm alarm;
    QTime testTime(8, 30);
    alarm.setAlarmTime(testTime);
    QCOMPARE(alarm.alarmTime(), testTime);
}

QTEST_MAIN(TestAlarm)

#include "tst_test_alarm.moc"
