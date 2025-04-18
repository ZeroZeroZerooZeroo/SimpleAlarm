#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "alarm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateTime();
    void onAlarmTriggered();
    void on_setTimeButton_clicked();
public:

    Ui::MainWindow *ui;
    Alarm *m_alarm;
    QTimer *m_timer;
    void setAlarmTime(const QTime &time);
    QTime alarmTime() const;

};
#endif // MAINWINDOW_H
