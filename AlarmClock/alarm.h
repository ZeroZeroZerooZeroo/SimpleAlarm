#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QTime>
#include <QMediaPlayer>
#include <QAudioOutput>
class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr);
    QTime alarmTime() const;
    void setAlarmTime(const QTime &time);
    bool isActive() const;
    void setActive(bool active);
    void setSource(const QString &filePath);
    void stop();

public slots:
    void checkAlarm(const QTime &currentTime);

private:
    QTime m_alarmTime;
    bool m_active = false;
    bool m_triggered = false;
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;

signals:
    void triggered();
};

#endif // ALARM_H
