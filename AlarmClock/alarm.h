#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QTime>
class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr);
    QTime alarmTime() const;
    void setAlarmTime(const QTime &time);

private:
    QTime m_alarmTime;
};

#endif // ALARM_H
