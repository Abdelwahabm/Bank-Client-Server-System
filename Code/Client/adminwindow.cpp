#include "adminwindow.h"
#include "ui_adminwindow.h"

const QRegularExpression AdminWindow::username_value("^[a-zA-Z0-9_]*$");
const QRegularExpression AdminWindow::password_value("\\s");

AdminWindow::AdminWindow(QWidget *parent, qint64 accountNumber, QTcpSocket *socket)
    : QMainWindow(parent), ui(new Ui::AdminWindow), socket(socket), accountNumber(accountNumber)
{
    ui->setupUi(this);
    // Set the window title
    setWindowTitle("Admin Window");

    // this attribute ensures that the widget’s memory is freed up
    // as soon as it is no longer needed
    setAttribute(Qt::WA_DeleteOnClose);

    //connect readyread slot
    connect(socket, &QTcpSocket::readyRead, this, &AdminWindow::readyRead);
    qDebug() <<"Constructor Called For Admin Window!";
}

AdminWindow::~AdminWindow()
{
    delete ui;
    // Emit the finished signal when the window is closed
    emit finished();
    qDebug() << "Destructor Called For Admin Window!";
}

void AdminWindow::readyRead()
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
        case 1:
            GetAccountNumberResponse_Handler(responseObject);
            break;
        case 2:
            ViewAccountBalanceResponse_Handler(responseObject);
            break;
        case 3:
            CreateNewAccountResponse_Handler(responseObject);
            break;
        case 4:
            DeleteAccountResponse_Handler(responseObject);
            break;
        case 5:
            ViewDatabaseResponse_Handler(responseObject);
            break;
        case 8:
            ViewTransactionHistoryResponse_Handler(responseObject);
            break;
        case 9:
            UpdateAccountResponse_Handler(responseObject);
            break;
        default:
            qInfo() << "Unvalid Response ID: " << responseId;
            break;
    }

    // qDebug() << responseData;
}


void AdminWindow::on_pushButton_get_account_number_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();

    ui->pushButton_get_account_number->setDisabled(true);
    ui->label_error->clear();
    // Set te request ID for Get Account Number
    quint8 requestId = 1;
    // Get the username
    QString username = ui->lineEdit_username->text();
    // Check if Username is not empty
    if (username.isEmpty())
    {
        qDebug() << "Please Enter the username!";
        // Set Error Msg
        ui->label_error->setText("Please Enter the username!");
        // enable clicking again to this button
        ui->pushButton_get_account_number->setEnabled(true);
        return;
    }

    // Check that the username contains only alphanumeric characters and underscores
    if (!username.contains(username_value))
    {
        qDebug() << "Unvalid Characters Entered in Username!";
        // Set Error Msg
        ui->label_error->setText("Unvalid Characters Entered in Username!");
        // enable clicking again to this button
        ui->pushButton_get_account_number->setEnabled(true);
        return;
    }

    // Construct the request with JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["username"] = username;
    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void AdminWindow::GetAccountNumberResponse_Handler(const QJsonObject &responseObject)
{
    ui->label_error->clear();
    ui->label_view_account_number->setText("Account Number: ");

    qint64 accountNumber = responseObject["accountNumber"].toVariant().toInt();
    bool userFound = responseObject["userFound"].toBool();
    if (userFound == true)
    {
        ui->label_view_account_number->setText("Account Number: "+ QString::number(accountNumber));
        ui->label_error->setText("Account Found");
        qDebug() << "Account Found: " << accountNumber;
    }
    else
    {
        ui->label_error->setText("User Account Not Found!");
        qDebug() << "User Account Not Found!";
    }
    // enable clicking again to this button
    ui->pushButton_get_account_number->setEnabled(true);
}

void AdminWindow::on_pbn_view_balance_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_view_balance->setDisabled(true);
    ui->label_error_viewbalance->clear();
    // Request ID for View Account Balance
    quint8 requestId = 2;
    // Get the account number from the UI
    qint64 accountNumber = ui->lnedit_accountnumber->text().toInt();

    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["accountNumber"] = accountNumber;
    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void AdminWindow::ViewAccountBalanceResponse_Handler(const QJsonObject &responseObject)
{

    ui->lbl_viewbalance->setText("Balance: ");
    ui->label_error_viewbalance->clear();

    double accountBalance = responseObject["balance"].toDouble();
    bool viewBalanceSuccess = responseObject["accountFound"].toBool();

    if (viewBalanceSuccess)
    {
        // Dispaly the balance
        ui->lbl_viewbalance->setText("Balance: " + QString::number(accountBalance) + "EGP");
        ui->label_error_viewbalance->setText("Operation Done Successfully!");
        qDebug() << "View Account Balance successful. Balance: " << accountBalance << "EGP";
    }
    else
    {
        // Set Error Msg
        ui->label_error_viewbalance->setText("User Account not found!");
        qDebug() << "User not found!";
    }
    // enable clicking again to this button
    ui->pbn_view_balance->setEnabled(true);
}

void AdminWindow::on_pbn_create_new_account_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_create_new_account->setDisabled(true);
    ui->lbl_error_create->clear();

    // Request ID for Create Account
    quint8 requestId = 3;

    // extract the informations
    QString username = ui->lnedit_username_input->text();
    QString password = ui->lnedit_password_input->text();
    QString name = ui->lnedit_name_input->text();
    quint8 age = ui->lnedit_age_input->text().toUInt();
    bool isAdmin = ui->chkbox_admin->isChecked();

    // Check if any of the required are empty
    if (username.isEmpty() || password.isEmpty() || name.isEmpty())
    {
        qDebug() << "Please Enter all the required!";
        ui->lbl_error_create->setText("All informations are have to be filled");
        ui->pbn_create_new_account->setEnabled(true);
        return;
    }

    // Username contains only characters and underscores
    if (!username.contains(username_value))
    {
        qDebug() << "Unvalid Characters Entered in Username!";
        // Set Error Msg
        ui->lbl_error_create->setText("Unvalid Characters Entered in Username!");
        // enable clicking again to this button
        ui->pbn_create_new_account->setEnabled(true);
        return;
    }

    // Check if the Password contains whitespace
    if (password.contains(password_value))
    {
        qDebug() << "Password have not contain whitespace!";
        ui->lbl_error_create->setText("Password have not contain whitespace!");
        ui->pbn_create_new_account->setEnabled(true);
        return;
    }

    // Check if the age is between 18 and 70
    if ((age < 18) || (age > 70))
    {
        qDebug() << "Age have be between 18 and 70!";
        ui->lbl_error_create->setText("Age have be between 18 and 70!");
        ui->pbn_create_new_account->setEnabled(true);
        return;
    }

    // Construct the request in JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["username"] = username;
    requestObject["password"] = password;
    requestObject["name"] = name;
    requestObject["age"] = age;
    requestObject["isAdmin"] = isAdmin;
    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());

}

void AdminWindow::CreateNewAccountResponse_Handler(const QJsonObject &responseObject)
{
    // delete error label msgs
    ui->lbl_error_create->clear();
    bool createAccountSuccess = responseObject["createAccountSuccess"].toBool();
    qint64 accountNumber = responseObject["accountNumber"].toVariant().toInt();

    // check if operation successed
    if (createAccountSuccess == true)
    {
        // send account created successfully to the label
        ui->lbl_error_create->setText("Account created Successfully, Account Number: "+ QString::number(accountNumber));
        qDebug() << "Account created Successfully, Account Number: " << accountNumber;
    }
    else
    {
        // send account didn't created successfully to the label
        QString errorMessage = responseObject["errorMessage"].toString();
        ui->lbl_error_create->setText("Error: " + errorMessage);
        qDebug() << "Account didn't created successfully " << errorMessage;
    }

    // enable clicking again to this button
    ui->pbn_create_new_account->setEnabled(true);
}

void AdminWindow::on_pbn_delete_account_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_delete_account->setDisabled(true);
    ui->lbl_error_delete->clear();

    // Request ID for Delete Account
    quint8 requestId = 4;

    bool Flag;
    qint64 accountNumber = ui->lnedit_delete_account_number->text().toInt(&Flag);

    if (!Flag)
    {
        ui->lbl_error_delete->setText("Please enter a valid account number!");
        qDebug() << "Please enter a valid account number!";
        // enable clicking again to this button
        ui->pbn_delete_account->setEnabled(true);
        // get out from this function
        return;
    }

    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["accountNumber"] = accountNumber;

    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
    // enable clicking again to this button
    ui->pbn_delete_account->setEnabled(true);
}

void AdminWindow::DeleteAccountResponse_Handler(const QJsonObject &responseObject)
{
    ui->lbl_error_delete->clear();

    bool deleteAccountSuccess = responseObject["deleteAccountSuccess"].toBool();

    if (deleteAccountSuccess == true)
    {
        ui->lbl_error_delete->setText("Account deleted successfully!");
        qDebug() << "Account deleted successfully!";
    }
    else
    {
        ui->lbl_error_delete->setText("Failed to delete account!");
        qDebug() << "Failed to delete account!";
    }
    ui->pbn_delete_account->setEnabled(true);
}

void AdminWindow::on_pbn_view_database_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();

    // Disable clicking on the button untile the server send the respond back
    ui->pbn_view_database->setDisabled(true);
    ui->lbl_view_database_error->clear();

    // Request ID for reading All User Data
    quint8 requestId = 5;

    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);

    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void AdminWindow::ViewDatabaseResponse_Handler(const QJsonObject &responseObject)
{
    ui->label_error->clear();
    bool viewUserDataSuccess = responseObject["fetchUserDataSuccess"].toBool();

    if (viewUserDataSuccess == true)
    {
        // clear all data in the table viewer
        ui->tbl_view_database->clearContents();
        // set the the insert row to 0
        ui->tbl_view_database->setRowCount(0);
        // get the data array from the response
        QJsonArray userDataArray = responseObject["userData"].toArray();
        // populate tbl_view_database with user data
        int row = 0;
        for (const auto &userValues : userDataArray)
        {
            // convert to JSON Object
            QJsonObject userValue = userValues.toObject();
            // set the row to insert data in
            ui->tbl_view_database->insertRow(row);
            // pass the elements of data to the table widget item
            ui->tbl_view_database->setItem(row, 0, new QTableWidgetItem(QString::number(userValue["accountNumber"].toInt())));
            ui->tbl_view_database->setItem(row, 1, new QTableWidgetItem(userValue["Username"].toString()));
            ui->tbl_view_database->setItem(row, 2, new QTableWidgetItem(userValue["Name"].toString()));
            ui->tbl_view_database->setItem(row, 3, new QTableWidgetItem(QString::number(userValue["Balance"].toDouble())));
            ui->tbl_view_database->setItem(row, 4, new QTableWidgetItem(QString::number(userValue["Age"].toInt())));
            // Increment row
            row++;
        }
    }
    else
    {
        // Set Error Msg
        ui->lbl_view_database_error->setText("Failed to fetch database!");
        qDebug() << "Failed to fetch database!";
    }
    // enable clicking again to this button
    ui->pbn_view_database->setEnabled(true);
}

void AdminWindow::on_pbn_view_transaction_history_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_view_transaction_history->setDisabled(true);
    // get the account number
    qint64 accountNumber=ui->lnedit_act_number_transaction_history->text().toInt();

    // check if the account number is less than or equal 0
    if (accountNumber <= 0)
    {
        // Set Error Msg
        ui->lbl_err_transaction_history->setText("Invalid Account Number, Please enter a valid number!");
        qDebug() << "Invalid Account Number, Please enter a valid number!";
        // enable clicking again to this button
        ui->pbn_view_transaction_history->setEnabled(true);
        return;
    }

    // Clear previous error messages
    ui->lbl_err_transaction_history->clear();
    // Request ID to View Transaction History
    quint8 requestId = 8;

    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["accountNumber"] = accountNumber;
    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}
void AdminWindow::ViewTransactionHistoryResponse_Handler(const QJsonObject &responseObject)
{
    // Clear error Msgs on the label
    ui->lbl_err_transaction_history->clear();
    // Recieve the respond
    bool viewTransactionHistorySuccess = responseObject["viewTransactionHistorySuccess"].toBool();

    bool isnumber;
    // get the number of desired transaction history
    quint8 Counts = ui->lnedit_num_of_counts_trans_history->text().toInt(&isnumber);

    // validate the transaction history is success
    if ( viewTransactionHistorySuccess == true && (isnumber || ui->lnedit_num_of_counts_trans_history->text().isEmpty()) )
    {
        // Clear existing data in tbl_transactionhistory
        ui->tbl_transaction_history->clearContents();
        // reset the row counts to 0 again
        ui->tbl_transaction_history->setRowCount(0);        
        // Get the transaction history from the response
        QJsonArray transactionHistoryArray = responseObject["transactionHistory"].toArray();
        // set the table row of transaction history data to 0
        int row = 0;

        for (const auto &transactionDataValue : transactionHistoryArray)
        {
            // print just the desired number of transactions
            if((Counts == row) && (!ui->lnedit_num_of_counts_trans_history->text().isEmpty()) &&
                isnumber)
            {
                break;
            }
            // convert to JSON Object
            QJsonObject transactionData = transactionDataValue.toObject();
            // set the row to insert data in
            ui->tbl_transaction_history->insertRow(row);
            // pass the elements of data to the table widget item
            ui->tbl_transaction_history->setItem(row, 0,
            new QTableWidgetItem(QString::number(transactionData["Amount"].toDouble())));
            ui->tbl_transaction_history->setItem(row, 1,
            new QTableWidgetItem(transactionData["Date"].toString()));
            ui->tbl_transaction_history->setItem(row, 2,
            new QTableWidgetItem(transactionData["Time"].toString()));
            // Increment row
            row++;
        }

        qDebug() << "Viewing Transaction History successeded!";
    }
    else
    {
        if(isnumber == false)
        {
            // Set Error Msg
            QString errorMessage = "Invalid Entered Number of Counts!";
            ui->lbl_err_transaction_history->setText(errorMessage);
            qDebug() << errorMessage;
        }
        else
        {
            // Set Error Msg
            QString errorMessage = responseObject["errorMessage"].toString();
            ui->lbl_err_transaction_history->setText(errorMessage);
            qDebug() << "Failed to view Transaction History! " << errorMessage;
        }

    }
    // enable clicking again to this button
    ui->pbn_view_transaction_history->setEnabled(true);
}

void AdminWindow::on_pbn_update_account_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_update_account->setDisabled(true);
    // Request ID for Update Account
    quint8 requestId = 9;

    // Get the necessary informations
    QString username = ui->lnedit_username_input->text();
    QString password = ui->lnedit_password_input->text();
    QString name = ui->lnedit_name_input->text();
    qint8 Age = ui->lnedit_age_input->text().toInt();
    QString accountnumber = ui->lnedit_update_acc_num->text();
    bool isAdmin = ui->chkbox_admin->isChecked();

    // Check if username is provided and matches the regex
    if (username.isEmpty() || !username_value.match(username).hasMatch())
    {
        qDebug() << "Warning: Please provide a valid username.";
        ui->lbl_error_create->setText("Please provide a valid username.");
        ui->pbn_update_account->setEnabled(true);
        return;
    }

    // Check if password is valid
    if (!password.isEmpty() && password_value.match(password).hasMatch())
    {
        qDebug() << "Password have not contain whitespace!";
        ui->lbl_error_create->setText("Password have not contain whitespace!");
        ui->pbn_update_account->setEnabled(true);
        return;
    }

    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["username"] = username;
    requestObject["age"] = Age;
    requestObject["accountNumber"] = accountnumber;
    requestObject["Admin"] = isAdmin;

    // Only add the fields to the JSON object if they are not empty
    if (!password.isEmpty() && !name.isEmpty())
    {
        requestObject["name"] = name;
        requestObject["password"] = password;
    }
    else
    {
        qDebug() << "Invalid name or Password!";
        ui->lbl_error_create->setText("Invalid Username or Password!");
        ui->pbn_update_account->setEnabled(true);
        return;
    }
    // Check if the age is between 18 and 70
    if ((Age < 18) || (Age > 70))
    {
        qDebug() << "Age have be between 18 and 70!";
        ui->lbl_error_create->setText("Age have be between 18 and 70!");
        ui->pbn_update_account->setEnabled(true);
        return;
    }

    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void AdminWindow::UpdateAccountResponse_Handler(const QJsonObject &responseObject)
{
    bool updateSuccess = responseObject["updateSuccess"].toBool();

    if (updateSuccess)
    {
        ui->lbl_error_create->setText("Update Account Done successfully!");
        qDebug() << "Update Account Done successfully!";
    }
    else
    {
        QString errorMessage = responseObject["errorMessage"].toString();
        ui->lbl_error_create->setText(errorMessage);
        qDebug() << "Failed to update account informations! " << errorMessage;
    }
    ui->pbn_update_account->setEnabled(true);
}
