#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_alarm(new Alarm(this))
    , m_timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(m_alarm, &Alarm::triggered, this, &MainWindow::onAlarmTriggered);
    m_timer->start(1000);
    updateTime();
}


MainWindow::~MainWindow()
{
    delete ui;
}
