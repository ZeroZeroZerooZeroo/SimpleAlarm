#include "alarm.h"

Alarm::Alarm(QObject *parent) : QObject(parent)
{

}

QTime Alarm::alarmTime() const {
    return m_alarmTime;
}

void Alarm::setAlarmTime(const QTime &time) {
    m_alarmTime = time;
}
bool Alarm::isActive() const
{
    return m_active;
}

void Alarm::setActive(bool active)
{
    m_active = active;
}
