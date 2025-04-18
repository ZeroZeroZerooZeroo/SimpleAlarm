#include "mainwindow.h"
#include "../AlarmClock/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_alarm(new Alarm(this))
    , m_timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateTime);
    //connect(m_alarm, &Alarm::triggered, this, &MainWindow::onAlarmTriggered);
    m_timer->start(1000);
    updateTime();
}
void MainWindow::updateTime()
{
    QTime current = QTime::currentTime();
    ui->statusLabel->setText("Current time: " + current.toString("hh:mm"));
    m_alarm->checkAlarm(current);
}

void MainWindow::onAlarmTriggered()
{
    ui->statusLabel->setText("ALARM!!!");

}

void MainWindow::setAlarmTime(const QTime &time)
{
    m_alarm->setAlarmTime(time);
}

QTime MainWindow::alarmTime() const
{
    return m_alarm->alarmTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}
