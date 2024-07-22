#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include "terminal.h"


class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(const QString &connectionName, QObject *parent = nullptr);
    ~Database();

    // Functions to manage the database
    bool openConnection();
    void closeConnection();
    void initializeDatabase();
    bool createTables();

private:
    QString connectionName;
    Terminal logger;
    QFile database;
    QJsonObject JsonObj;
};


#endif // DATABASE_H
