#include "clientresponse.h"

ClientResponse::ClientResponse(qintptr socketDescriptor, QObject *parent)
    : QObject(parent), socketDescriptor(socketDescriptor), logger("ClientResponse")
{
    if (socketDescriptor == -1)
    {
        logger.cmd("Invalid socket descriptor.");
        return;
    }

    // idleTimer = new QTimer(this);
    // connect(idleTimer, &QTimer::timeout, this, &ClientResponse::disconnectIdleClient);
    // idleTimer->start(IDLE_TIMEOUT);

    logger.cmd("Object Created!");

}


ClientResponse::~ClientResponse()
{
    if(databaseManager != nullptr)
    {
        databaseManager->closeConnection();
        delete databaseManager;
        databaseManager = nullptr;
    }

    // Delete the QTimer object
    // if(idleTimer != nullptr)
    // {
    //     if(idleTimer->isActive())
    //     {
    //         idleTimer->stop();
    //     }
    //     delete idleTimer;
    //     idleTimer = nullptr;
    // }
    logger.cmd("Object Destroyed.");

}

void ClientResponse::run()
{
    // Create QTcpSocket
    clientSocket = new QTcpSocket();

    if (!clientSocket->setSocketDescriptor(socketDescriptor))
    {
        logger.cmd("Failed to set socket descriptor. Thread will be finished.");
        emit clientDisconnected(socketDescriptor);
        return;
    }

    // Create databaseManager object for the client connected
    databaseManager = new Database(QString::number(socketDescriptor), this);
    if(databaseManager == nullptr)
    {
        logger.cmd("Failed to create DatabaseManager.");
        return;
    }
    databaseManager->openConnection();

    connect(clientSocket, &QTcpSocket::readyRead, this, &ClientResponse::readyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &ClientResponse::socketDisconnected);
    logger.cmd(QString("Client setup completed in thread ID: %1").arg((quintptr)QThread::currentThreadId()));
}

void ClientResponse::readyRead()
{
    // Reset idle timer on every message received
    // idleTimer->start(IDLE_TIMEOUT);

    QByteArray data = clientSocket->readAll();
    qInfo() << "Data : "<<data;
    RespondHandler requestHandler(this);
    QByteArray responseData = requestHandler.Respond_Handler(data);
    sendResponseToClient(responseData);
}

void ClientResponse::sendResponseToClient(QByteArray responseData)
{
    if (clientSocket->write(responseData) == -1)
    {
        logger.cmd("Failed to write data to client: " + clientSocket->errorString());
    }
}

void ClientResponse::disconnectIdleClient()
{
    logger.cmd("Client idle. Disconnecting...");
    clientSocket->disconnectFromHost();
}

void ClientResponse::socketDisconnected()
{
    emit clientDisconnected(socketDescriptor);
    logger.cmd(QString("Client disconnected in thread ID: %1").arg((quintptr)QThread::currentThreadId()));
    deleteLater();
}
