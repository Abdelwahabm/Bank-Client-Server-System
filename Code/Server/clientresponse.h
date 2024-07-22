#ifndef CLIENTRESPONSE_H
#define CLIENTRESPONSE_H


#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QTimer>

#include "terminal.h"
#include "respondhandler.h"
#include "Database.h"

// Idle time out 30 seconds
#define IDLE_TIMEOUT 30000


class ClientResponse : public QObject
{
    Q_OBJECT
public:
    explicit ClientResponse(qintptr socketDescriptor, QObject *parent = nullptr);
    ~ClientResponse();

signals:
    void clientDisconnected(qintptr socketDescriptor);

public slots:
    void run();
    void readyRead();
    void sendResponseToClient(QByteArray responseData);

private slots:
    void disconnectIdleClient();
    void socketDisconnected();

private:
    qintptr socketDescriptor;
    QTcpSocket *clientSocket = nullptr;
    Database* databaseManager = nullptr;
    QTimer *idleTimer = nullptr;
    Terminal logger;

};

#endif // CLIENTRESPONSE_H
