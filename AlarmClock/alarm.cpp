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
