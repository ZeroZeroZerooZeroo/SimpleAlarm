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
    bool isActive() const;
    void setActive(bool active);

private:
    QTime m_alarmTime;
    bool m_active = false;
};

#endif // ALARM_H
