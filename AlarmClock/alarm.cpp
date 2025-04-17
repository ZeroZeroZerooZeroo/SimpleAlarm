#include "alarm.h"
#include <QUrl>
Alarm::Alarm(QObject *parent)
    : QObject(parent),
    m_player(new QMediaPlayer(this)),
    m_audioOutput(new QAudioOutput(this))
{
    m_player->setAudioOutput(m_audioOutput);
    m_audioOutput->setVolume(100);
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

void Alarm::checkAlarm(const QTime &currentTime)
{
    if(m_active && !m_triggered && currentTime >= m_alarmTime) {
        m_triggered = true;
        emit triggered();
    }
}

void Alarm::setSource(const QString &filePath)
{
    m_player->setSource(QUrl::fromLocalFile(filePath));
}
