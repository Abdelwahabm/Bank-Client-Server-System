#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSslSocket>
#include <QSslConfiguration>
#include <QSslError>
#include <QRegularExpression>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Connected();
    void show_last_Window();
    void readyRead();

private slots:
    void on_pushButton_login_clicked();
    void on_pbn_connect_clicked();
    void stateChaged(QAbstractSocket::SocketState socketState);
    void SslErrors(const QList<QSslError> &errors);

private:
    Ui::MainWindow *ui;
    QSslSocket *socket;

    // Regular expressions for username and password validation
    static const QRegularExpression username_value;
    static const QRegularExpression password_value;

    void connectToServer(void);
    void Login_Handler(const QJsonObject &responseObject);

};
#endif // MAINWINDOW_H
