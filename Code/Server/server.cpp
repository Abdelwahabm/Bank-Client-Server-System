#include "server.h"


server::server(QObject *parent)
    : QTcpServer(parent), logger("Server")
{
    logger.cmd("New Operation Created!");
    if (!listen(QHostAddress::LocalHost, 54321))
    {
        logger.cmd("Failed to start server: " + errorString());
    }
    else
    {
        logger.cmd("server started on Port 54321");
    }
}

server::~server()
{
    // search for all of those requestes to close and delete them
    for (auto it = requestThreads.begin(); it != requestThreads.end(); ++it)
    {
        it.value()->quit();
        it.value()->wait();
        delete it.value();
    }
    // close the server
    close();
    //
    logger.cmd("All Threads have been closed");
    logger.cmd("server breaked down!");
}

void server::incomingConnection(qintptr socketDescription)
{
    qDebug() << "CreatNewConnection Function : " << socketDescription;

    QThread* requestThread = new QThread();
    requestThreads.insert(socketDescription, requestThread);

    ClientResponse* clientResponse = new ClientResponse(socketDescription);
    clientResponse->moveToThread(requestThread);

    connect(requestThread, &QThread::started, clientResponse, &ClientResponse::run);
    connect(clientResponse, &ClientResponse::clientDisconnected, this, &server::DisconnectedHandler);
    connect(clientResponse, &ClientResponse::destroyed, requestThread, &QThread::quit);

    requestThread->start();
    logger.cmd(QString("Client connected with socket descriptor: %1").arg(socketDescription));
}

void server::DisconnectedHandler(qintptr socketDescription)
{
    // Tells the thread's event loop to exit with return code 0 (success).
    // Equivalent to calling QThread::exit(0)
    requestThreads.value(socketDescription)->quit();
    // Blocks the thread until The thread associated with this QThread object has finished execution
    requestThreads.value(socketDescription)->wait();
    // delete this thread request
    delete requestThreads.value(socketDescription);
    // Removes all the items that have the key key from the map.
    requestThreads.remove(socketDescription);
    logger.cmd(QString("Client disconnected with socket socketDescription: %1").arg(socketDescription));
}
