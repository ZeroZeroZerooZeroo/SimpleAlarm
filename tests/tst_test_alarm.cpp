#include <QCoreApplication>
#include <QtTest>
#include "../AlarmClock/alarm.h"
#include "../AlarmClock/alarm.cpp"
#include "../AlarmClock/mainwindow.h"
#include "../AlarmClock/ui_mainwindow.h"
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
    void testAlarmStop();
    void testUpdateTime();
    void testAlarmTriggered();
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

void TestAlarm::testAlarmStop()
{
    Alarm alarm;
    alarm.setActive(true);
    alarm.stop();
    QVERIFY(!alarm.isActive());
}

void TestAlarm::testUpdateTime()
{
    MainWindow window;

    QTime beforeTest = QTime::currentTime();

    window.updateTime();

    QString labelText = window.ui->statusLabel->text();

    QVERIFY(labelText.contains(beforeTest.toString("hh:mm")));

    QSignalSpy spy(window.m_alarm, &Alarm::checkAlarm);
    window.updateTime();
    QCOMPARE(spy.count(), 1);
}


QTEST_MAIN(TestAlarm)

#include "tst_test_alarm.moc"
