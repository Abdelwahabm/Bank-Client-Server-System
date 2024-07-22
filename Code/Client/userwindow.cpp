#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, qint64 accountNumber, QTcpSocket *socket)
    : QMainWindow(parent), ui(new Ui::UserWindow), socket(socket), accountNumber(accountNumber)
{
    ui->setupUi(this);
    // Set the window title
    setWindowTitle("User Window");

    // this attribute ensures that the widget’s memory is freed up
    // as soon as it is no longer needed
    setAttribute(Qt::WA_DeleteOnClose);
    //connect readyread slot
    connect(socket, &QTcpSocket::readyRead, this, &UserWindow::readyRead);
    qDebug() << "Constructor of User Window called!";
}

UserWindow::~UserWindow()
{
    delete ui;
    // emiting this signal to show the previous window
    emit finished();
    qDebug() << "Destructor of the User Window Called !";
}

void UserWindow::readyRead()
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
    case 2:
        View_Account_Balance_Handler(responseObject);
        break;
    case 6:
        Transaction_Handler(responseObject);
        break;
    case 7:
        Transfer_Handler(responseObject);
        break;
    case 8:
        View_Transaction_History_Handler(responseObject);
        break;
    default:
        qInfo() << "Unvalid Response ID: " << responseId;
        break;
    }
}



void UserWindow::on_pbn_make_trasnaction_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_make_trasnaction->setDisabled(true);

    QString transfer_Value = ui->lnedit_amount->text();
    bool conversion_Done;
    double Value = transfer_Value.toDouble(&conversion_Done);

    // Validate the Value
    if (!conversion_Done || transfer_Value.isEmpty() || Value == 0)
    {
        // Display an error message in transaction error label
        ui->lbl_transaction_error->setText("Invalid Value entered, Please enter a valid number!");
        // enable clicking again to this button
        ui->pbn_make_trasnaction->setEnabled(true);
        return;
    }

    // Clear any previous error messages because he entered a valid number
    ui->lbl_transaction_error->clear();

    // Request ID for Make Transaction
    quint8 requestId = 6;

    // Create a JSON object for the transaction request
    QJsonObject transactionRequest;
    transactionRequest["requestId"] = static_cast<int>(requestId);
    transactionRequest["accountNumber"] = accountNumber;
    transactionRequest["amount"] = Value;

    // Convert JSON object to JSON Document
    QJsonDocument jsonRequest(transactionRequest);

    // Send the request to the server
    socket->write(jsonRequest.toJson());

}

void UserWindow::Transaction_Handler(const QJsonObject &responseObject)
{

    double newBalance = responseObject["newBalance"].toDouble();
    bool transactionSuccess = responseObject["transactionSuccess"].toBool();

    ui->lbl_transaction_error->clear();

    if (transactionSuccess == true)
    {
        ui->lbl_transaction_error->setText("Transaction Done");
        qDebug() <<"Transaction success, New balance: " <<newBalance<< "EGP";
    }
    else
    {
        QString errorMessage = responseObject["errorMessage"].toString();
        ui->lbl_transaction_error->setText("Transaction failed: " + errorMessage);
        qDebug() << "Transaction failed: " << errorMessage;
    }
    // enable clicking again to this button
    ui->pbn_make_trasnaction->setEnabled(true);
}


void UserWindow::on_pbn_view_balance_clicked()
{
    // Request ID for viewing the account balance
    int requestId = 2;

    // To ensure that iam connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_view_balance->setDisabled(true);

    // construct the JSON object request
    QJsonObject requestObject;
    requestObject["requestId"] = requestId;
    requestObject["accountNumber"] = accountNumber;
    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(requestObject);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void UserWindow::View_Account_Balance_Handler(const QJsonObject &responseObject)
{
    ui->label_view_balance->setText("Balance Amount: ");
    double accountBalance = responseObject["balance"].toDouble();
    bool viewBalanceSuccess = responseObject["accountFound"].toBool();

    if (viewBalanceSuccess)
    {
        ui->label_view_balance->setText("Balance Amount: " + QString::number(accountBalance)+"EGP");
        qDebug() << "Viewing Account Balance success, Balance Amount: " << accountBalance<<"EGP";
    }
    else
    {
        ui->label_view_balance->setText("Failed to view Account Balance!");
        qDebug() << "Failed to view Account Balance.";
    }

    // enable clicking again to this button
    ui->pbn_view_balance->setEnabled(true);
}



void UserWindow::on_pbn_view_transaction_histroy_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();

    // Disable clicking on the button untile the server send the respond back
    ui->pbn_view_transaction_histroy->setDisabled(true);

    // Request ID for View Transaction History
    quint8 requestId = 8;
    // Construct the request JSON object
    QJsonObject requestObject;
    requestObject["requestId"] = static_cast<int>(requestId);
    requestObject["accountNumber"] = accountNumber;
    // Convert JSON object to JSON Document
    QJsonDocument jsonRequest(requestObject);

    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void UserWindow::View_Transaction_History_Handler(const QJsonObject &responseObject)
{
    // Clear any previous error messages
    ui->lbl_err_transaction_history->clear();
    // Recieve the respond
    bool viewTransactionHistorySuccess = responseObject["viewTransactionHistorySuccess"].toBool();

    // validate the transaction history is success
    if (viewTransactionHistorySuccess == true)
    {
        // Clear existing data in tbl_transactionhistory
        ui->tbl_view_histroy_transaction->clearContents();
        // reset the row counts to 0 again
        ui->tbl_view_histroy_transaction->setRowCount(0);
        // Get the transaction history from the response
        QJsonArray transactionHistoryArray = responseObject["transactionHistory"].toArray();
        // get the number of desired transaction history
        quint32 Counts = ui->lnedit_num_of_counts_trans_history->text().toInt();
        qDebug() << "Transaction : " << responseObject;

        // set the table row of transaction history data to 0
        quint32 row = 0;
        for(const auto &transactionValue : transactionHistoryArray)
        {
            // print just the desired number of transactions
            if(Counts == row)
            {
                break;
            }
            qDebug() << "Transaction : " << transactionValue.toObject();

            // convert to JSON Object
            QJsonObject transactionData = transactionValue.toObject();
            // set the row to insert data in
            ui->tbl_view_histroy_transaction->insertRow(row);
            // pass the elements of data to the table widget item
            ui->tbl_view_histroy_transaction->setItem(row, 0, new QTableWidgetItem(QString::number(transactionData["Amount"].toDouble())));
            ui->tbl_view_histroy_transaction->setItem(row, 1, new QTableWidgetItem(transactionData["Date"].toString()));
            ui->tbl_view_histroy_transaction->setItem(row, 2, new QTableWidgetItem(transactionData["Time"].toString()));
            // Increment row
            row++;
        }
        qDebug() << "View Transaction History success ";
    }
    else
    {
        // Display an Error Msg
        ui->lbl_err_transaction_history->setText("Failed to view Transaction History!");
        qDebug() << "Failed to view Transaction History!";
    }
    // enable clicking again to this button
    ui->pbn_view_transaction_histroy->setEnabled(true);
}


void UserWindow::on_pbn_mk_transfer_clicked()
{
    // make sure that i am connected to the server
    emit reconnect();
    // Disable clicking on the button untile the server send the respond back
    ui->pbn_mk_transfer->setDisabled(true);
    // Get the account number to transfer to
    qint64 toAccountNumber = ui->lnedit_to_accountnumber->text().toInt();

    // Validate the tansfer to the AccountNumber
    if (toAccountNumber <= 0)
    {

        ui->lbl_mk_trnsf_err->setText("Invalid 'To Account Number'. Please enter a valid number.");
        ui->pbn_mk_transfer->setEnabled(true);
        return;
    }

    // Check if the 'from' and 'to' account numbers are the same
    if (accountNumber == toAccountNumber)
    {
        ui->lbl_mk_trnsf_err->setText("You cannot transfer money to yourself!");
        ui->pbn_mk_transfer->setEnabled(true);
        return;
    }

    // Get the transfer value
    QString transfer_Value = ui->lnedit_trnsfr_amount->text();
    bool conversionDone;
    double Value = transfer_Value.toDouble(&conversionDone);

    // Validate the transfer amount
    if (!conversionDone || transfer_Value.isEmpty() || Value <= 0)
    {
        ui->lbl_mk_trnsf_err->setText("Invalid transfer amount. Please enter a valid positive number greater than zero.");
        ui->pbn_mk_transfer->setEnabled(true);
        return;
    }

    // Clear any previous error messages
    ui->lbl_mk_trnsf_err->clear();

    // Request ID for Transfer Money
    quint8 requestId = 7;
    // Create JSON object to transfer request
    QJsonObject transferRequest;
    transferRequest["requestId"] = static_cast<int>(requestId);
    transferRequest["fromAccountNumber"] = accountNumber;
    transferRequest["toAccountNumber"] = toAccountNumber;
    transferRequest["amount"] = Value;

    // Convert JSON object to JSON document
    QJsonDocument jsonRequest(transferRequest);
    // Send the request to the server
    socket->write(jsonRequest.toJson());
}

void UserWindow::Transfer_Handler(const QJsonObject &responseObject)
{
    // recieve the respond
    double newFromBalance = responseObject["newFromBalance"].toDouble();
    double newToBalance = responseObject["newToBalance"].toDouble();
    bool transferSuccess = responseObject["transferSuccess"].toBool();

    // Clear any previous error messages
    ui->lbl_mk_trnsf_err->clear();

    if (transferSuccess == true)
    {

        ui->lbl_mk_trnsf_err->setText("Transfer success ");
        qDebug() << "Transfer Done, New From balance: " << newFromBalance << "EGP"
                 << " , New To balance: " << newToBalance << "EGP";
    }
    else
    {
        QString errorMessage = responseObject["errorMessage"].toString();
        ui->lbl_mk_trnsf_err->setText("Transfer Failed: " +errorMessage);
        qDebug() << "Transfer Failed: " <<errorMessage;
    }

    // enable clicking again to this button
    ui->pbn_mk_transfer->setEnabled(true);
}


void UserWindow::on_pushButton_get_account_number_clicked()
{
    // Display Account number on the label
    ui->label_account_number->setText("Account Number: " + QString::number(accountNumber));
}
