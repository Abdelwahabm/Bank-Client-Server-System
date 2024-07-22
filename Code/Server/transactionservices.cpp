#include "transactionservices.h"


TransactionServices::TransactionServices(QObject *parent)
    : QObject(parent),  logger("TransactionManager")
{
    // TransactionServices Launched
    logger.cmd("TransactionManager Object Created!");
}

TransactionServices::~TransactionServices()
{
    logger.cmd("TransactionManager Object Destroyed!");
}


QJsonObject TransactionServices::makeTransaction(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["transactionSuccess"] = false;

    // Extract the necessary data from the request JSON
    qint32 accountNumber = requestJson["accountNumber"].toInt();
    double amount = requestJson["amount"].toDouble();
    qDebug() << "Account Number: " << accountNumber;

    // Load the database from the JSON file
    QJsonObject databaseJson = loadDatabase();
    QJsonArray usersPersonalDataArray = databaseJson["Users_Personal_Data"].toArray();

    // Check if the account number exists in the database
    bool accountExists = false;
    for (int i = 0; i < usersPersonalDataArray.size(); ++i)
    {
        QJsonObject personalDataObject = usersPersonalDataArray[i].toObject();
        qint32 personalAccountNumber = personalDataObject["accountNumber"].toInt();

        if (personalAccountNumber == accountNumber)
        {
            // The account number exists in the Users_Personal_Data section
            accountExists = true;
            qDebug() << "Account Exist" ;

            // Update the balance in the Users_Personal_Data section
            double currentBalance = personalDataObject["Balance"].toDouble();
            personalDataObject["Balance"] = currentBalance + amount;
            usersPersonalDataArray[i] = personalDataObject;
            qDebug() << usersPersonalDataArray[i] << personalDataObject["Balance"] << currentBalance + amount;

            break;
        }
    }

    if (!accountExists)
    {
        responseJson["errorMessage"] = "Account does not exist";
        return responseJson;
    }

    // Update the Users_Personal_Data section in the database
    databaseJson["Users_Personal_Data"] = usersPersonalDataArray;

    // Save the updated database to the JSON file
    if (!saveDatabase(databaseJson))
    {
        responseJson["errorMessage"] = "Failed to update balance";
        return responseJson;
    }

    // Log the transaction
    if (!logTransaction(accountNumber, amount))
    {
        responseJson["errorMessage"] = "Failed to log transaction";
        return responseJson;
    }

    responseJson["transactionSuccess"] = true;
    return responseJson;
}

QJsonObject TransactionServices::makeTransfer(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["transferSuccess"] = false;

    // Extract the necessary data from the request JSON
    qint32 fromAccountNumber = requestJson["fromAccountNumber"].toVariant().toInt();
    qint32 toAccountNumber = requestJson["toAccountNumber"].toVariant().toInt();
    double amount = requestJson["amount"].toDouble();

    // Load the database from the JSON file
    QJsonObject databaseJson = loadDatabase();
    QJsonArray usersPersonalDataArray = databaseJson["Users_Personal_Data"].toArray();

    // Check if the 'from' account number exists in the database
    bool fromAccountExists = false;
    int fromAccountIndex = -1;
    for (int i = 0; i < usersPersonalDataArray.size(); ++i)
    {
        QJsonObject personalDataObject = usersPersonalDataArray[i].toObject();
        qint32 personalAccountNumber = personalDataObject["accountNumber"].toInt();

        if (personalAccountNumber == fromAccountNumber)
        {
            // The account number exists in the Users_Personal_Data section
            fromAccountExists = true;
            fromAccountIndex = i;

            // Check if the 'from' account has sufficient balance
            double currentBalance = personalDataObject["Balance"].toDouble();
            if (currentBalance < amount)
            {
                responseJson["errorMessage"] = "Insufficient balance in the 'from' account";
                return responseJson;
            }

            // Update the balance in the Users_Personal_Data section
            personalDataObject["Balance"] = currentBalance - amount;
            usersPersonalDataArray[i] = personalDataObject;

            break;
        }
    }

    if (!fromAccountExists)
    {
        responseJson["errorMessage"] = "Account number 'fromAccountNumber' does not exist";
        return responseJson;
    }

    // Check if the 'to' account number exists in the database
    bool toAccountExists = false;
    int toAccountIndex = -1;
    for (int i = 0; i < usersPersonalDataArray.size(); ++i)
    {
        QJsonObject personalDataObject = usersPersonalDataArray[i].toObject();
        qint32 personalAccountNumber = personalDataObject["accountNumber"].toInt();

        if (personalAccountNumber == toAccountNumber)
        {
            // The account number exists in the Users_Personal_Data section
            toAccountExists = true;
            toAccountIndex = i;

            break;
        }
    }

    if (!toAccountExists)
    {
        responseJson["errorMessage"] = "Account number 'toAccountNumber' does not exist";
        return responseJson;
    }

    // Update the balance in the Users_Personal_Data section for the 'to' account
    QJsonObject toAccountObject = usersPersonalDataArray[toAccountIndex].toObject();
    double toAccountBalance = toAccountObject["Balance"].toDouble();
    toAccountObject["Balance"] = toAccountBalance + amount;
    usersPersonalDataArray[toAccountIndex] = toAccountObject;

    // Update the Users_Personal_Data section in the database
    databaseJson["Users_Personal_Data"] = usersPersonalDataArray;

    // Save the updated database to the JSON file
    if (!saveDatabase(databaseJson))
    {
        responseJson["errorMessage"] = "Failed to update balances";
        return responseJson;
    }

    // Log the transfer in the transaction history
    if (!logTransaction(fromAccountNumber, -amount) || !logTransaction(toAccountNumber, amount))
    {
        responseJson["errorMessage"] = "Failed to log transaction";
        return responseJson;
    }

    responseJson["transferSuccess"] = true;
    responseJson["newFromBalance"] = usersPersonalDataArray[fromAccountIndex].toObject()["Balance"];
    responseJson["newToBalance"] = usersPersonalDataArray[toAccountIndex].toObject()["Balance"];

    return responseJson;
}

QJsonObject TransactionServices::viewTransactionHistory(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["viewTransactionHistorySuccess"] = false;

    // Extract the account number from the request JSON
    qint32 accountNumber = requestJson["accountNumber"].toInt();

    // Load the transaction history from the JSON file
    QJsonArray transactionHistoryJson = loadTransactionHistory();

    // Filter the transaction history for the specified account number
    QJsonArray filteredTransactions;
    for (const QJsonValue& transaction : transactionHistoryJson)
    {
        qint32 transactionAccountNumber = transaction["accountNumber"].toInt();
        if (transactionAccountNumber == accountNumber)
        {
            filteredTransactions.append(transaction.toObject());
            qDebug() << "Transaction : " << transaction.toObject();
        }
    }

    responseJson["viewTransactionHistorySuccess"] = true;
    responseJson["transactionHistory"] = filteredTransactions;

    return responseJson;
}


QJsonObject TransactionServices::loadDatabase()
{
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open database file");
        return QJsonObject();
    }

    QByteArray databaseJsonData = databaseFile.readAll();
    databaseFile.close();

    QJsonParseError jsonParseError;
    QJsonDocument databaseJsonDoc = QJsonDocument::fromJson(databaseJsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError)
    {
        logger.cmd("Failed to parse database JSON: " + jsonParseError.errorString());
        return QJsonObject();
    }

    if (!databaseJsonDoc.isObject())
    {
        logger.cmd("Invalid database JSON format");
        return QJsonObject();
    }

    return databaseJsonDoc.object();
}

bool TransactionServices::saveDatabase(const QJsonObject& databaseJson)
{
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        logger.cmd("Failed to open database file for writing");
        return false;
    }

    databaseFile.seek(0);
    QJsonDocument databaseJsonDoc(databaseJson);
    databaseFile.write(databaseJsonDoc.toJson());
    databaseFile.close();

    qDebug() << "Data Saved Successfully!" ;
    return true;
}

bool TransactionServices::logTransaction(qint32 accountNumber, double amount)
{
    // Load the transaction history from the JSON file
    QJsonArray transactionHistoryJson = loadTransactionHistory();

    // Get the current date and time
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDate = currentDateTime.toString("dd-MM-yyyy");
    QString formattedTime = currentDateTime.toString("hh:mm:ss");

    // Prepare the transaction data
    QJsonObject transactionJson;
    transactionJson["accountNumber"] = accountNumber;
    transactionJson["Date"] = formattedDate;
    transactionJson["Time"] = formattedTime;
    transactionJson["Amount"] = amount;

    // Add the transaction to the transaction history
    transactionHistoryJson.append(transactionJson);
    qDebug() << "transactionHistoryJson" << transactionJson;
    qDebug() << "Data logged Successfully!" ;

    // Save the updated transaction history to the JSON file
    return saveTransactionHistory(transactionHistoryJson);
}

QJsonArray TransactionServices::loadTransactionHistory()
{
    QFile transactionHistoryFile("bankDatabase.json");
    if (!transactionHistoryFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open transaction history file");
        return QJsonArray();
    }

    QByteArray transactionHistoryJsonData = transactionHistoryFile.readAll();
    transactionHistoryFile.close();

    QJsonParseError jsonParseError;
    QJsonDocument transactionHistoryJsonDoc = QJsonDocument::fromJson(transactionHistoryJsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError)
    {
        logger.cmd("Failed to parse transaction history JSON: " + jsonParseError.errorString());
        return QJsonArray();
    }

    if (!transactionHistoryJsonDoc.isObject())
    {
        logger.cmd("Invalid transaction history JSON format");
        return QJsonArray();
    }

    QJsonObject transactionHistoryJsonObject = transactionHistoryJsonDoc.object();

    if (!transactionHistoryJsonObject.contains("transactionHistory"))
    {
        // Create a new transactionHistory section if it doesn't exist
        transactionHistoryJsonObject["transactionHistory"] = QJsonArray();
    }

    return transactionHistoryJsonObject["transactionHistory"].toArray();
}
bool TransactionServices::saveTransactionHistory(const QJsonArray& transactionHistoryJson)
{
    QFile transactionHistoryFile("bankDatabase.json");
    if (!transactionHistoryFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        logger.cmd("Failed to open transaction history file for writing");
        return false;
    }

    QByteArray transactionHistoryJsonData = transactionHistoryFile.readAll();
    transactionHistoryFile.close();

    QJsonParseError jsonParseError;
    QJsonDocument transactionHistoryJsonDoc = QJsonDocument::fromJson(transactionHistoryJsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError)
    {
        logger.cmd("Failed to parse transaction history JSON: " + jsonParseError.errorString());
        return false;
    }

    if (!transactionHistoryJsonDoc.isObject())
    {
        logger.cmd("Invalid transaction history JSON format");
        return false;
    }

    QJsonObject transactionHistoryJsonObject = transactionHistoryJsonDoc.object();

    transactionHistoryJsonObject["transactionHistory"] = transactionHistoryJson;

    QJsonDocument updatedDocument(transactionHistoryJsonObject);
    transactionHistoryFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    transactionHistoryFile.write(updatedDocument.toJson());
    transactionHistoryFile.close();

    return true;
}
QJsonArray TransactionServices::loadUsersPersonalData()
{
    QFile transactionHistoryFile("bankDatabase.json");
    if (!transactionHistoryFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open transaction history file");
        return QJsonArray();
    }

    QByteArray transactionHistoryJsonData = transactionHistoryFile.readAll();
    transactionHistoryFile.close();

    QJsonParseError jsonParseError;
    QJsonDocument transactionHistoryJsonDoc = QJsonDocument::fromJson(transactionHistoryJsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError)
    {
        logger.cmd("Failed to parse transaction history JSON: " + jsonParseError.errorString());
        return QJsonArray();
    }

    if (!transactionHistoryJsonDoc.isObject())
    {
        logger.cmd("Invalid transaction history JSON format");
        return QJsonArray();
    }

    QJsonObject transactionHistoryJsonObject = transactionHistoryJsonDoc.object();

    if (!transactionHistoryJsonObject.contains("Users_Personal_Data"))
    {
        logger.cmd("Users_Personal_Data section does not exist");
        return QJsonArray();
    }

    QJsonValue usersPersonalDataValue = transactionHistoryJsonObject["Users_Personal_Data"];
    if (!usersPersonalDataValue.isArray())
    {
        logger.cmd("Invalid Users_Personal_Data JSON format");
        return QJsonArray();
    }

    return usersPersonalDataValue.toArray();
}

QJsonArray TransactionServices::loadAccounts()
{
    QFile transactionHistoryFile("bankDatabase.json");
    if (!transactionHistoryFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open transaction history file");
        return QJsonArray();
    }

    QByteArray transactionHistoryJsonData = transactionHistoryFile.readAll();
    transactionHistoryFile.close();

    QJsonParseError jsonParseError;
    QJsonDocument transactionHistoryJsonDoc = QJsonDocument::fromJson(transactionHistoryJsonData, &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError)
    {
        logger.cmd("Failed to parse transaction history JSON: " + jsonParseError.errorString());
        return QJsonArray();
    }

    if (!transactionHistoryJsonDoc.isObject())
    {
        logger.cmd("Invalid transaction history JSON format");
        return QJsonArray();
    }

    QJsonObject transactionHistoryJsonObject = transactionHistoryJsonDoc.object();

    if (!transactionHistoryJsonObject.contains("Accounts"))
    {
        logger.cmd("Accounts section does not exist");
        return QJsonArray();
    }

    QJsonValue accountsValue = transactionHistoryJsonObject["Accounts"];
    if (!accountsValue.isArray())
    {
        logger.cmd("Invalid Accounts JSON format");
        return QJsonArray();
    }

    return accountsValue.toArray();
}
