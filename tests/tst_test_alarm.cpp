#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

class test_alarm : public QObject
{
    Q_OBJECT

public:
    test_alarm();
    ~test_alarm();

private slots:
    void test_case1();
};

test_alarm::test_alarm() {}

test_alarm::~test_alarm() {}

void test_alarm::test_case1() {}

QTEST_MAIN(test_alarm)

#include "tst_test_alarm.moc"
