#include <QCoreApplication>
#include <signal.h>
#include <QTimer>

#include "accountservices.h"
#include "database.h"
#include "server.h"
#include "terminal.h"
#include "respondhandler.h"

void handleSignal(int signal);
void initializeDatabase();

int main(int argc, char *argv[])
{
    QCoreApplication bankServer(argc, argv);

    // Handle SIGINT, SIGTERM, and SIGHUP
    signal(SIGINT, handleSignal);
    signal(SIGTERM, handleSignal);
    //it's annoying in windows to implement this...
    //signal(SIGHUP, handleSignal);

    initializeDatabase();

    quint8 requestId = 3;
    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["username"] = "mohamed";
    requestObject["password"] = "1234";
    requestObject["name"] = "Mohamed Ahmed";
    requestObject["age"] = 26;
    requestObject["isAdmin"] = true;

    QJsonObject requestObject2;
    requestObject2["requestId"] = static_cast<int>(requestId);
    requestObject2["username"] = "abdelwahab";
    requestObject2["password"] = "1234";
    requestObject2["name"] = "Mohamed Abdelwahab";
    requestObject2["age"] = 26;
    requestObject2["isAdmin"] = false;

    // QJsonObject data = "{\n    \"age\": 26,\n    \"isAdmin\": true,\n    \"name\": \"mohamed\",\n    \"password\": \"1234\",\n    \"requestId\": 3,\n    \"username\": \"mohamed\"\n}\n";
    // AccountManager a;


    server bankserver(&bankServer);

    Terminal mainLogger("Bank Server Main");

    if (!bankserver.isListening())
    {
        mainLogger.cmd("Failed to start the server.");
        return 1;
    }


    ClientServices *accountManager = new ClientServices();

    accountManager->createNewAccount(requestObject);
    accountManager->createNewAccount(requestObject2);

    mainLogger.cmd("Event loop Started.");

    bankServer.processEvents();
    delete accountManager;
    return bankServer.exec();
}

void initializeDatabase()
{
    Database databaseManager("DatabaseInitializationConnection");
    databaseManager.initializeDatabase();
}

void handleSignal(int signal)
{
    Q_UNUSED(signal);
    Terminal signalLogger("ExitSignal");

    signalLogger.cmd("Received exit signal. Initiating server shutdown.");
    QCoreApplication::quit();
}
