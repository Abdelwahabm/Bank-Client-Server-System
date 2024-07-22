#include "database.h"

Database::Database(const QString &connectionName, QObject *parent)
    : QObject(parent), connectionName(connectionName), logger("DatabaseManager")
{
    logger.cmd("Database Object Created!");
    QDir dir("database");
    if (dir.exists() == false)
        dir.mkdir("database");

    database.setFileName(dir.absolutePath() + "/bankDatabase.json");
}

Database::~Database()
{
    if (database.isOpen())
    {
        database.close();
    }

    logger.cmd("Data base Object Destroyed!");
}

bool Database::openConnection()
{
    if (!database.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        logger.cmd(QString("Failed to Open database connection '%1'").arg(connectionName));
        return false;
    }

    logger.cmd(QString("Opened database connection '%1'").arg(connectionName));
    return true;
}

void Database::closeConnection()
{
    if (!database.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        database.close();
        logger.cmd(QString("Closed database connection '%1'").arg(connectionName));
    }
    else
    {
        logger.cmd(QString("Database connection '%1' is not open.").arg(connectionName));
    }
}


void Database::initializeDatabase()
{
    QFile databaseFile("bankDatabase.json");
    if (databaseFile.exists())
    {
        logger.cmd("bankdatabase already exists.");
    }
    else
    {
        // Create the file if it doesn't exist
        if (databaseFile.open(QIODevice::WriteOnly))
        {
            databaseFile.write("{}");
            databaseFile.close();
            logger.cmd("Created database file: bankdatabase.json");
            openConnection();
            createTables();
            closeConnection();
        }
        else
        {
            logger.cmd("Failed to create database file!");
        }
    }
}

bool Database::createTables()
{
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadWrite))
    {
        logger.cmd("Failed to open database file.");
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(databaseFile.readAll());
    QJsonObject database = doc.object();

    // Create Accounts table
    QJsonObject accountsTable;
    accountsTable["data"] = QJsonArray();
    database["Accounts"] = accountsTable;

    // Insert default admin account
    QJsonObject defaultAdminData;
    defaultAdminData["Username"] = "admin";
    defaultAdminData["Password"] = "admin";
    defaultAdminData["Admin"] = true;
    QJsonObject accountsObject = database["Accounts"].toObject();
    QJsonValue accountsDataValue = accountsObject["data"];
    QJsonArray accountsData = accountsDataValue.toArray();
    accountsData.append(defaultAdminData);
    database["Accounts"].toObject().insert("data", accountsData);

    // Create Users_Personal_Data table
    QJsonObject usersPersonalDataTable;
    usersPersonalDataTable["data"] = QJsonArray();
    database["Users_Personal_Data"] = usersPersonalDataTable;

    // Create Transaction_History table
    QJsonObject transactionHistoryTable;
    transactionHistoryTable["data"] = QJsonArray();
    database["Transaction_History"] = transactionHistoryTable;

    databaseFile.seek(0);
    databaseFile.write(QJsonDocument(database).toJson());
    databaseFile.resize(databaseFile.pos());

    databaseFile.close();

    logger.cmd("Created all tables successfully.");

    return true;

}
