#include "terminal.h"


Terminal::Terminal(const QString &title, QObject *parent)
    : QObject(parent), title_name(title)
{}

Terminal::~Terminal()
{}

void Terminal::cmd(const QString &message)
{
    // take this mutex
    QMutexLocker locker(&mutex);
    // set the message format to pass to the terminal file to save in
    QString printedMessage = QString("%1: %2").arg(title_name, message);

    qDebug() << printedMessage;
    // release this mutex
}
