#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include "mainwindow.h"

namespace Ui
{
    class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr,qint64 accountNumber = 0,
                         QTcpSocket *socket = nullptr);
    ~AdminWindow();


private:
    Ui::AdminWindow *ui;
    QTcpSocket *socket;
    qint64 accountNumber;

    // Regular expressions for username and password validation
    static const QRegularExpression username_value;
    static const QRegularExpression password_value;

    // Handlers for admin Interactions
    void CreateNewAccountResponse_Handler(const QJsonObject &responseObject);
    void GetAccountNumberResponse_Handler(const QJsonObject &responseObject);
    void ViewAccountBalanceResponse_Handler(const QJsonObject &responseObject);
    void DeleteAccountResponse_Handler(const QJsonObject &responseObject);
    void ViewDatabaseResponse_Handler(const QJsonObject &responseObject);
    void ViewTransactionHistoryResponse_Handler(const QJsonObject &responseObject);
    void UpdateAccountResponse_Handler(const QJsonObject &responseObject);


signals:
    void reconnect();
    void finished();

private slots:
    void readyRead();
    void on_pushButton_get_account_number_clicked();
    void on_pbn_view_balance_clicked();
    void on_pbn_create_new_account_clicked();
    void on_pbn_delete_account_clicked();
    void on_pbn_view_database_clicked();
    void on_pbn_view_transaction_history_clicked();
    void on_pbn_update_account_clicked();

};

#endif // ADMINWINDOW_H
