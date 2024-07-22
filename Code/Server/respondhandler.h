#ifndef RESPONDHANDLER_H
#define RESPONDHANDLER_H


#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMutex>
#include <QByteArray>

#include "accountservices.h"
#include "transactionservices.h"
#include "Database.h"
#include "terminal.h"


class RespondHandler : public QObject
{
    Q_OBJECT

public:
    explicit RespondHandler(QObject *parent = nullptr);
    ~RespondHandler();
    QByteArray Respond_Handler(QByteArray requestData);

private:
    QMutex mutex;
    QString connectionName;
    ClientServices *accountManager = nullptr;
    TransactionServices *transactionManager = nullptr;
    Terminal logger;

};

#endif // RESPONDHANDLER_H
