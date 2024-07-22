#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThread>
#include <QMap>
#include "clientresponse.h"
#include "terminal.h"

class server : public QTcpServer
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
    ~server();

private:
    QMap<qintptr, QThread*> requestThreads;
    Terminal logger;
protected:
    void incomingConnection(qintptr socketDescription) override;
private slots:
    void DisconnectedHandler(qintptr socketDescription);

};
#endif // SERVER_H
