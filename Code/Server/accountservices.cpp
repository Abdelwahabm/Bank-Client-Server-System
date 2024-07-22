#include "accountservices.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ClientServices::ClientServices(QObject* parent)
    : QObject(parent), logger("AccountManager")
{
    logger.cmd("AccountManager Object Created.");
}

ClientServices::~ClientServices()
{
    logger.cmd("AccountManager Object Destroyed");
}

QJsonObject ClientServices::login(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["loginSuccess"] = false;

    // Extract the username and password from the request JSON
    QString username = requestJson["username"].toString();
    QString password = requestJson["password"].toString();

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    databaseFile.close();

    if (!databaseDoc.isObject())
    {
        logger.cmd("Invalid database file format.");
        return responseJson;
    }

    QJsonObject databaseJson = databaseDoc.object();

    // Find the account in the database
    QJsonArray accountsArray = databaseJson["Accounts"].toArray();
    QJsonObject accountJson;
    for (const QJsonValue& accountValue : accountsArray)
    {
        QJsonObject account = accountValue.toObject();
        if (account["Username"].toString() == username && account["Password"].toString() == password)
        {
            accountJson = account;
            break;
        }
    }

    if (!accountJson.isEmpty())
    {
        // Login successful
        responseJson["loginSuccess"] = true;
        responseJson["accountNumber"] = accountJson["accountNumber"].toVariant().toInt();
        responseJson["isAdmin"] = accountJson["Admin"].toBool();
    }
    else
    {
        // Login failed
        logger.cmd("Login failed.");
    }

    return responseJson;
}

QJsonObject ClientServices::getAccountNumber(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["userFound"] = false;

    // Extract the username from the request JSON
    QString username = requestJson["username"].toString();

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    databaseFile.close();

    if (!databaseDoc.isObject())
    {
        logger.cmd("Invalid database file format.");
        return responseJson;
    }

    QJsonObject databaseJson = databaseDoc.object();

    // Find the account in the database
    QJsonArray accountsArray = databaseJson["Accounts"].toArray();
    for (const QJsonValue& accountValue : accountsArray)
    {
        QJsonObject account = accountValue.toObject();
        if (account["Username"].toString() == username)
        {
            // User found
            responseJson["accountNumber"] = account["accountNumber"].toVariant().toInt();
            responseJson["userFound"] = true;
            break;
        }
    }

    if (!responseJson["userFound"].toBool())
    {
        // User not found
        logger.cmd("User not found.");
    }

    return responseJson;
}

QJsonObject ClientServices::getAccountBalance(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["accountFound"] = false;

    // Extract the account number from the request JSON
    qint64 accountNumber = requestJson["accountNumber"].toVariant().toInt();

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadOnly))
    {
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    databaseFile.close();

    if (!databaseDoc.isObject())
    {
        logger.cmd("Invalid database file format.");
        return responseJson;
    }

    QJsonObject databaseJson = databaseDoc.object();

    // Find the account in the database
    QJsonArray personalDataArray = databaseJson["Users_Personal_Data"].toArray();
    for (const QJsonValue& personalDataValue : personalDataArray)
    {
        QJsonObject personalData = personalDataValue.toObject();
        if (personalData["accountNumber"].toVariant().toInt() == accountNumber)
        {
            // Account found
            responseJson["balance"] =personalData["Balance"].toVariant().toDouble();
            responseJson["accountFound"] = true;
            break;
        }
    }

    if (!responseJson["accountFound"].toBool())
    {
        // Account not found
        logger.cmd("Account not found.");
    }

    return responseJson;
}


QJsonObject ClientServices::createNewAccount(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["createAccountSuccess"] = false;
    qInfo() << "Inside Create New Account ";

    // Extract the necessary data from the request JSON
    bool isAdmin = requestJson["isAdmin"].toBool();
    QString username = requestJson["username"].toString();
    QString password = requestJson["password"].toString();
    QString name = requestJson["name"].toString();
    int age = requestJson["age"].toInt();
    double balance = 0.0;

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        responseJson["errorMessage"] = "Failed to open database file.";
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    QJsonObject databaseJson = databaseDoc.object();
    QJsonArray accountsArray = databaseJson["Accounts"].toArray();

    for(int i = 0;i < accountsArray.size() ; ++i)
    {

        QJsonObject accountObject = accountsArray[i].toObject();
        if (accountObject["Username"].toString() == username)
        {
            responseJson["errorMessage"] = "Username already exists.";
            logger.cmd("Username already exists.");
            databaseFile.close();
            return responseJson;
        }
    }
    // Generate a new account number
    qint64 currentMillis = QDateTime::currentMSecsSinceEpoch();
    qint32 accountNumber = static_cast<qint32>(currentMillis % 0x7FFFFFFF); // Use modulo to ensure it's within 31-bit range

    // Insert the new account into the Accounts array
    QJsonObject accountData;
    accountData["Username"] = username;
    accountData["Password"] = password;
    accountData["Admin"] = isAdmin;
    accountData["accountNumber"] = accountNumber;

    accountsArray.append(accountData);
    databaseJson["Accounts"] = accountsArray;

    // Insert the personal data into the Users_Personal_Data array
    QJsonObject personalData;
    personalData["Username"] = username;
    personalData["accountNumber"] = accountNumber;
    personalData["Name"] = name;
    personalData["Age"] = age;
    personalData["Balance"] = balance;

    QJsonArray personalDataArray = databaseJson["Users_Personal_Data"].toArray();
    personalDataArray.append(personalData);
    databaseJson["Users_Personal_Data"] = personalDataArray;

    // Write the updated JSON data back to the file
    databaseFile.seek(0);
    databaseFile.resize(0); // Clear the file contents
    databaseFile.write(QJsonDocument(databaseJson).toJson());
    databaseFile.close();

    responseJson["createAccountSuccess"] = true;
    responseJson["accountNumber"] = static_cast<qint32>(accountNumber);
    return responseJson;
}


QJsonObject ClientServices::deleteAccount(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["deleteAccountSuccess"] = false;

    // Extract the account number from the request JSON
    qint32 accountNumber = requestJson["accountNumber"].toVariant().toInt();

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        responseJson["errorMessage"] = "Failed to open database file.";
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    QJsonObject databaseJson = databaseDoc.object();

    // Remove the account from the Accounts array
    QJsonArray accountsArray = databaseJson["Accounts"].toArray();
    bool accountRemoved = false;
    for (int i = 0; i < accountsArray.size(); ++i)
    {
        QJsonObject accountObject = accountsArray[i].toObject();
        if (accountObject["accountNumber"].toInt() == accountNumber)
        {
            accountsArray.removeAt(i);
            accountRemoved = true;
            break;
        }
    }

    if (!accountRemoved)
    {
        responseJson["errorMessage"] = "Account not found in Accounts array.";
        logger.cmd("Account not found in Accounts array.");
        databaseFile.close();
        return responseJson;
    }

    databaseJson["Accounts"] = accountsArray;

    // Remove the personal data from the Users_Personal_Data array
    QJsonArray personalDataArray = databaseJson["Users_Personal_Data"].toArray();
    bool personalDataRemoved = false;
    for (int i = 0; i < personalDataArray.size(); ++i)
    {
        QJsonObject personalDataObject = personalDataArray[i].toObject();
        if (personalDataObject["accountNumber"].toInt() == accountNumber)
        {
            personalDataArray.removeAt(i);
            personalDataRemoved = true;
            break;
        }
    }

    if (!personalDataRemoved)
    {
        responseJson["errorMessage"] = "Personal data not found in Users_Personal_Data array.";
        logger.cmd("Personal data not found in Users_Personal_Data array.");
        databaseFile.close();
        return responseJson;
    }

    databaseJson["Users_Personal_Data"] = personalDataArray;

    // Remove the transaction history for the account
    QJsonArray transactionHistoryArray = databaseJson["transactionHistory"].toArray();
    for (int i = transactionHistoryArray.size() - 1; i >= 0; --i)
    {
        QJsonObject transactionObject = transactionHistoryArray[i].toObject();
        if (transactionObject["accountNumber"].toInt() == accountNumber)
        {
            qDebug() << "Delete :" << transactionHistoryArray[i];
            transactionHistoryArray.removeAt(i);
        }
    }

    databaseJson["transactionHistory"] = transactionHistoryArray;

    // Write the updated JSON data back to the file
    databaseFile.seek(0);
    databaseFile.resize(0); // Clear the file contents
    databaseFile.write(QJsonDocument(databaseJson).toJson());
    databaseFile.close();

    responseJson["deleteAccountSuccess"] = true;
    return responseJson;
}


QJsonObject ClientServices::updateUserData(QJsonObject requestJson)
{
    QJsonObject responseJson;
    responseJson["updateSuccess"] = false;

    // Extract the necessary data from the request JSON
    QString username = requestJson["username"].toString();
    QString name = requestJson["name"].toString();
    QString password = requestJson["password"].toString();
    qint8 age = requestJson["age"].toInt();
    qint32 accountNumber = requestJson["accountNumber"].toVariant().toInt();
    bool isAdmin = requestJson["Admin"].toVariant().toBool();

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        responseJson["errorMessage"] = "Failed to open database file.";
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    QJsonObject databaseJson = databaseDoc.object();

    // Find the account data in the Accounts array
    QJsonArray accountsArray = databaseJson["Accounts"].toArray();

    QJsonObject accountData;
    bool accountFound = false;
    for (int i = 0; i < accountsArray.size() ; ++i)
    {
        QJsonObject accountObject = accountsArray[i].toObject();
        if (accountObject["accountNumber"].toVariant().toInt() == accountNumber)
        {
            accountData = accountObject;
            // Update the password in the account data
            if (!password.isEmpty())
            {
                accountData["Password"] = password;
            }
            // Update the password in the account data
            if (!username.isEmpty())
            {
                accountData["Username"] = username;
            }

            // Update the Admin in the account data
            accountData["Admin"] = isAdmin;

            accountsArray.replace(i, accountData);

            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        responseJson["errorMessage"] = "Account not found";
        logger.cmd("Account not found.");
        databaseFile.close();
        return responseJson;
    }

    databaseJson["Accounts"] = accountsArray;

    // Update the name in the Users_Personal_Data array
    if (!name.isEmpty())
    {
        qint32 accountNumber = accountData["accountNumber"].toInt();

        QJsonArray personalDataArray = databaseJson["Users_Personal_Data"].toArray();
        for (int i = 0; i < personalDataArray.size(); ++i)
        {
            QJsonObject personalDataObject = personalDataArray[i].toObject();
            if (personalDataObject["accountNumber"].toInt() == accountNumber)
            {
                personalDataObject["Name"] = name;
                personalDataObject["Age"] = age;
                personalDataObject["Username"] = username;
                personalDataArray.replace(i, personalDataObject);
                break;
            }
        }

        databaseJson["Users_Personal_Data"] = personalDataArray;
    }

    // Write the updated JSON data back to the file
    databaseFile.seek(0);
    databaseFile.resize(0); // Clear the file contents
    databaseFile.write(QJsonDocument(databaseJson).toJson());
    databaseFile.close();

    responseJson["updateSuccess"] = true;
    return responseJson;
}



QJsonObject ClientServices::viewDatabase()
{
    QJsonObject responseJson;
    responseJson["fetchUserDataSuccess"] = false;

    // Load the JSON file database
    QFile databaseFile("bankDatabase.json");
    if (!databaseFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        responseJson["errorMessage"] = "Failed to open database file.";
        logger.cmd("Failed to open database file.");
        return responseJson;
    }

    QJsonDocument databaseDoc = QJsonDocument::fromJson(databaseFile.readAll());
    databaseFile.close();

    if (databaseDoc.isNull())
    {
        responseJson["errorMessage"] = "Failed to parse JSON data.";
        logger.cmd("Failed to parse JSON data.");
        return responseJson;
    }

    responseJson["fetchUserDataSuccess"] = true;
    responseJson["userData"] = databaseDoc.object()["Users_Personal_Data"];
    qDebug() << "View DataBase Respond Done!" << responseJson;

    return responseJson;
}
