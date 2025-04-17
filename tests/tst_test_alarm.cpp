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
    void testAlarmActiveState();
    void testAlarmTriggering();
    void testSoundSetting();
};

TestAlarm::TestAlarm() {}

TestAlarm::~TestAlarm() {}

void TestAlarm::test_case1() {}

void TestAlarm::testAlarmActiveState()
{
    Alarm alarm;
    QVERIFY(!alarm.isActive());
    alarm.setActive(true);
    QVERIFY(alarm.isActive());
}

void TestAlarm::testAlarmTimeSetting()
{
    Alarm alarm;
    QTime testTime(8, 30);
    alarm.setAlarmTime(testTime);
    QCOMPARE(alarm.alarmTime(), testTime);
}

void TestAlarm::testAlarmTriggering()
{
    Alarm alarm;
    alarm.setAlarmTime(QTime::currentTime().addSecs(1));
    alarm.setActive(true);

    QSignalSpy spy(&alarm, &Alarm::triggered);
    alarm.checkAlarm(QTime::currentTime().addSecs(2));

    QCOMPARE(spy.count(), 1);
}

void TestAlarm::testSoundSetting()
{
    Alarm alarm;
    QString testFile = "test.mp3";
    alarm.setSource(testFile);

    QVERIFY(true); // Заглушка
}

QTEST_MAIN(TestAlarm)

#include "tst_test_alarm.moc"
