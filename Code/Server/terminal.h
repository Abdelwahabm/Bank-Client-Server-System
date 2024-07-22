#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QMutex>
#include <QDebug>

class Terminal : public QObject
{
    Q_OBJECT
public:
    explicit Terminal(const QString &title, QObject *parent = nullptr);
    ~Terminal();
    void cmd(const QString &message);

private:
    QString title_name;
    QMutex mutex;
};

#endif // TERMINAL_H
