#ifndef ACCOUNTSERVICES_H
#define ACCOUNTSERVICES_H

#include <QObject>
#include <QtGlobal>

#include "Database.h"
#include "terminal.h"


class ClientServices : public QObject
{
    Q_OBJECT
public:
    explicit ClientServices(QObject *parent = nullptr);
    ~ClientServices();

    // Functions related to account management
    QJsonObject login(QJsonObject requestJson);
    QJsonObject getAccountNumber(QJsonObject requestJson);
    QJsonObject getAccountBalance(QJsonObject requestJson);
    QJsonObject createNewAccount(QJsonObject requestJson);
    QJsonObject deleteAccount(QJsonObject requestJson);
    QJsonObject updateUserData(QJsonObject requestJson);
    QJsonObject viewDatabase();

    Terminal logger;
};

#endif // ACCOUNTSERVICES_H
