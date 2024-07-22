#ifndef USERWINDOW_H
#define USERWINDOW_H

#include "mainwindow.h"

namespace Ui
{
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr,qint64 accountNumber = 0,
                        QTcpSocket *socket = nullptr);
    ~UserWindow();

signals:
    void reconnect();
    void finished();

private slots:
    void readyRead();
    void on_pbn_view_balance_clicked();
    void on_pbn_make_trasnaction_clicked();
    void on_pbn_mk_transfer_clicked();
    void on_pbn_view_transaction_histroy_clicked();
    void on_pushButton_get_account_number_clicked();

private:
    Ui::UserWindow *ui;
    QTcpSocket *socket;
    qint64 accountNumber;

    void View_Account_Balance_Handler(const QJsonObject &responseObject);
    void Transaction_Handler(const QJsonObject &responseObject);
    void Transfer_Handler(const QJsonObject &responseObject);
    void View_Transaction_History_Handler(const QJsonObject &responseObject);
};

#endif // USERWINDOW_H
