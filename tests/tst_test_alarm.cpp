#include <QCoreApplication>
#include <QtTest>
#include "../AlarmClock/alarm.h"
#include "../AlarmClock/alarm.cpp"
#include "../AlarmClock/mainwindow.h"
#include "../AlarmClock/ui_mainwindow.h"
#include "mock_file_dialog.h"

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
    void testTimeSetting();
    void testSetsAlarmTime();
    void testSelectsMusicFile();
    void testStopsAlarm();
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
    QCoreApplication::processEvents();
    QVERIFY(labelText.contains(beforeTest.toString("hh:mm")));

    QSignalSpy spy(window.m_alarm, &Alarm::checkAlarm);
    window.updateTime();
    QCOMPARE(spy.count(), 1);
}

void TestAlarm::testAlarmTriggered()
{
    MainWindow window;

    window.onAlarmTriggered();
    QCOMPARE(window.ui->statusLabel->text(), QString("ALARM!!!"));

    QSignalSpy spy(window.m_alarm, &Alarm::triggered);

    emit window.m_alarm->triggered();

    QCOMPARE(spy.count(), 1);

    QCOMPARE(window.ui->statusLabel->text(), QString("ALARM!!!"));
}

void TestAlarm::testTimeSetting()
{
    MainWindow window;
    QTime testTime(12, 30);
    window.setAlarmTime(testTime);

    QCOMPARE(window.alarmTime(), testTime);
}

void TestAlarm::testSetsAlarmTime()
{
    MainWindow window;

    QTime testTime(8, 30);
    window.ui->timeEdit->setTime(testTime);

    window.on_setTimeButton_clicked();

    QCOMPARE(window.m_alarm->alarmTime(), testTime);
}


void TestAlarm::testSelectsMusicFile()
{
    MainWindow window;

    #define QFileDialog MockFileDialog

    window.on_selectMusicButton_clicked();
    QVERIFY(!window.m_alarm->currentMusicPath().isEmpty());

#undef QFileDialog
}

void TestAlarm::testStopsAlarm()
{
    MainWindow window;
    window.m_alarm->setActive(true);

    window.on_stopButton_clicked();
    QVERIFY(!window.m_alarm->isActive());
}

QTEST_MAIN(TestAlarm)

#include "tst_test_alarm.moc"
