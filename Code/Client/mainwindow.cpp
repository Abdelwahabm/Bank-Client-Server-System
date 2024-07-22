#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "userwindow.h"


// Regular expressions for username and password validation
const QRegularExpression MainWindow::username_value("^[a-zA-Z0-9_]*$");
const QRegularExpression MainWindow::password_value("\\s");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QSslSocket(this);
    // Set the window elements
    setWindowTitle("Login Window");
    // this->setWindowIcon(QIcon("bank.jpg"));

    // Set The Proyocole of Transmission to TLS 1.3 Later
    socket->setProtocol(QSsl::TlsV1_3OrLater);

    // connect the handlling of state changed
    connect(socket, &QSslSocket::stateChanged, this, &MainWindow::stateChaged);

    // connect the handlling of readyRead
    connect(socket, &QSslSocket::readyRead, this, &MainWindow::readyRead);

    // connect the handlling of sslErrors
    connect(socket, QOverload<const QList<QSslError>&>::of(&QSslSocket::sslErrors),
            this, &MainWindow::SslErrors);

    // try to connect to the server
    connectToServer();
}

// Main Window Destructor
MainWindow::~MainWindow()
{
    // Flushing the socket before ending the program and then disconnecting
    socket->flush();
    socket->disconnect();
    // Delete the socket and ui
    delete socket;
    delete ui;
}

void MainWindow::connectToServer()
{
    // Get the IP from the text line edit
    QString IP_Address = ui->lineEdit_ip->text();

    qInfo() << IP_Address;
    //try to connect to the server
    // hostName may be an IP address in string form (e.g., "43.195.83.32"),
    // or it may be a host name (e.g., "example.com"). QAbstractSocket will do a lookup
    // only if required. port is in native byte order.
    socket->connectToHost(IP_Address, 54321);
}

void MainWindow::Connected()
{
    // Check if the state is connected
    if (socket->state() != QAbstractSocket::ConnectedState)
    {
        // trying to connect to the server
        connectToServer();
        // Wait for the socket to connect  default is 30 seconds
        if (!socket->waitForConnected())
        {
            qInfo() << "Could not connect to server!";
            QMessageBox::warning(nullptr,"Warning","Could not connect to server!",QMessageBox::Ok);
        }
    }
}

void MainWindow::stateChaged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::ConnectedState)
    {
        // if The socket connected
        // change the text to connected state
        // and the checkbox to checked
        // disable the connect button to make the client unable to press the button
        ui->chkbox->setText("Connected");
        ui->chkbox->setChecked(true);
        ui->pbn_connect->setEnabled(false);
        ui->chkbox->setEnabled(false);

    }
    else
    {
        // The socket is not connected
        // change the text to Not connected state
        // and the checkbox to not checked
        // ensable the connect button to make the client unable to press the button
        ui->chkbox->setText("Not connected !");
        ui->chkbox->setChecked(false);
        ui->pbn_connect->setEnabled(true);
        ui->chkbox->setEnabled(false);

    }
}

void MainWindow::SslErrors(const QList<QSslError> &errors)
{
    for (const QSslError &error : errors)
    {
        qDebug() << "SSL error: " << error.errorString();
    }
}

void MainWindow::on_pbn_connect_clicked()
{
    connectToServer();
}


void MainWindow::readyRead()
{
    // Read data from socket
    QByteArray responseData = socket->readAll();
    // Uncompress the response data to convert it to QByte Array
    responseData = qUncompress(responseData);
    // convert to JSON Document Format
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

    // is the response is a JSON object
    if (!jsonResponse.isObject())
    {
        qInfo() << "Wrong JSON response from the server!";
        return;
    }

    // here i recieved the right json format
    QJsonObject responseObject = jsonResponse.object();
    int responseId = responseObject["responseId"].toInt();

    switch (responseId)
    {
    case 0:
        Login_Handler(responseObject);
        qInfo() << "Response ID: " << responseId;
        break;
    default:
        qInfo() << "Unvalid Response ID: " << responseId;
        break;
    }
}

// Slot for handling login button click
void MainWindow::on_pushButton_login_clicked()
{
    // Request ID for login
    quint8 Id_Request = 0;

    // Get the username and password from the Line Edit
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    // Check if Username and Password are not empty
    if ((username.isEmpty()) || (password.isEmpty()))
    {

        qDebug() << "Please Enter The Username and Password First!";

        QMessageBox::warning(nullptr, "Warning", "Please Enter The Username and Password First!"
                             , QMessageBox::Ok);

        return;
    }

    // Check if the Username field contains only alphanumeric characters and underscores
    if (!username.contains(username_value))
    {

        qDebug() << "Username Must Only Contain Alphanumeric Characters!";
        QMessageBox::warning(nullptr, "Warning", "Username Must Only Contain Alphanumeric Characters!", QMessageBox::Ok);
        return;
    }

    // Check if the password contains spaces
    if (password.contains(password_value))
    {
        qDebug() << "Password Must not Contain Spaces!";
        QMessageBox::warning(nullptr, "Warning", "Password Must not Contain Spaces!", QMessageBox::Ok);
        return;
    }


    // Construct the request JSON object
    QJsonObject Object_request;
    Object_request["requestId"] = static_cast<int>(Id_Request);
    Object_request["username"] = username;
    Object_request["password"] = password;

    // Converting JSON object to a JSON Document
    QJsonDocument JsonRequest(Object_request);
    // Send the request to the server
    socket->write(JsonRequest.toJson());
}

// Handling login response from the server
void MainWindow::Login_Handler(const QJsonObject &responseObject)
{
    // Extract information from the response object
    bool loginSuccess = responseObject["loginSuccess"].toBool();
    // Get account number
    qint64 accountNumber = responseObject["accountNumber"].toVariant().toInt();
    // Get Authority even user or admin
    bool isAdmin = responseObject["isAdmin"].toBool();


    // Check if a successful login happened
    if (loginSuccess == true)
    {
        // switch to the appropriate window even admin or
        // user based on user type
        if (isAdmin == true)
        {
//////////// Disconnect the readyRead signal from the MainWindow slot
            disconnect(socket, &QSslSocket::readyRead, this, &MainWindow::readyRead);
            AdminWindow *adminWindow = new AdminWindow(nullptr, accountNumber, socket);

            // Connect the in the AdminWindow object to show admin window in the MainWindow object
            connect(adminWindow, &AdminWindow::finished,this, &MainWindow::show_last_Window);
            // Connect the reconnectNeeded signal in the AdminWindow object
            // to Connected in the MainWindow object
            connect(adminWindow, &AdminWindow::reconnect,this, &MainWindow::Connected);

            qDebug() << adminWindow;
            adminWindow->show();
        }
        else
        {
            // Disconnect the readyRead signal from the MainWindow slot
            disconnect(socket, &QSslSocket::readyRead, this, &MainWindow::readyRead);
            UserWindow *userWindow = new UserWindow(nullptr, accountNumber, socket);

            // Connect the finished signal in the UserWindow object to show last window in the MainWindow object
            connect(userWindow, &UserWindow::finished,this, &MainWindow::show_last_Window);
            // Connect the reconnect signal in the UserWindow object
            // to Connected in the MainWindow object
            connect(userWindow, &UserWindow::reconnect,this, &MainWindow::Connected);

            qDebug() << "User Window Launched";
            userWindow->show();
        }
        // hide the current window
        this->hide();
    }
    else
    {
        // Display a login failed message
        QMessageBox::warning(this, "Login Failed", "Invalid username or password, Please try again.", QMessageBox::Ok);
    }
}

void MainWindow::show_last_Window()
{
    connect(socket, &QSslSocket::readyRead, this, &MainWindow::readyRead);
    // Clear the login window
    ui->lineEdit_Username->clear();
    ui->lineEdit_Password->clear();
    // Print the sender object
    QObject *senderObject = sender();
    qDebug() << "The current Window: " <<senderObject;
    // Show the login window
    this->show();
}
