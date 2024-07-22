#ifndef TRANSACTIONSERVICES_H
#define TRANSACTIONSERVICES_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "Database.h"
#include "terminal.h"


class TransactionServices : public QObject
{
    Q_OBJECT
public:
    explicit TransactionServices(QObject *parent = nullptr);
    ~TransactionServices();

    // Functions related to transaction management

    QJsonObject makeTransaction(QJsonObject requestJson);
    QJsonObject makeTransfer(QJsonObject requestJson);
    QJsonObject viewTransactionHistory(QJsonObject requestJson);
    QJsonObject loadDatabase();
    bool saveDatabase(const QJsonObject& databaseJson);
    bool logTransaction(qint32 accountNumber, double amount);
    QJsonArray loadTransactionHistory();
    bool saveTransactionHistory(const QJsonArray& transactionHistoryJson);
    QJsonArray loadUsersPersonalData();
    QJsonArray loadAccounts();

private:
    QString connectionName;
    Terminal logger;


};

#endif // TRANSACTIONSERVICES_H
