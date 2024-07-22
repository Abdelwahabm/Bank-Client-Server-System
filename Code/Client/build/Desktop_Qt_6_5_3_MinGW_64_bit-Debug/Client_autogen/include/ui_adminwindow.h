/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QTableWidget *tbl_view_database;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbn_view_database;
    QLabel *lbl_view_database_error;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QTableWidget *tbl_transaction_history;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_err_transaction_history;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_5;
    QLineEdit *lnedit_act_number_transaction_history;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *lnedit_num_of_counts_trans_history;
    QPushButton *pbn_view_transaction_history;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_accountdeletion;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_account_number_delete;
    QLineEdit *lnedit_delete_account_number;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pbn_delete_account;
    QLabel *lbl_error_delete;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_view_account_number;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_get_account_number;
    QLabel *label_error;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *lbl_viewbalance;
    QLabel *label_error_viewbalance;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lbl_accountnumber;
    QLineEdit *lnedit_accountnumber;
    QPushButton *pbn_view_balance;
    QGridLayout *gridLayout;
    QLabel *lbl_accountcreation;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_username_input;
    QLineEdit *lnedit_username_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_password;
    QLineEdit *lnedit_password_input;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_name;
    QLineEdit *lnedit_name_input;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_age;
    QLineEdit *lnedit_age_input;
    QLabel *lbl_error_create;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pbn_create_new_account;
    QCheckBox *chkbox_admin;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_6;
    QLineEdit *lnedit_update_acc_num;
    QPushButton *pbn_update_account;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(781, 693);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        tbl_view_database = new QTableWidget(centralwidget);
        if (tbl_view_database->columnCount() < 5)
            tbl_view_database->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl_view_database->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl_view_database->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl_view_database->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl_view_database->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl_view_database->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tbl_view_database->setObjectName("tbl_view_database");

        verticalLayout_6->addWidget(tbl_view_database);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbn_view_database = new QPushButton(centralwidget);
        pbn_view_database->setObjectName("pbn_view_database");

        horizontalLayout->addWidget(pbn_view_database);

        lbl_view_database_error = new QLabel(centralwidget);
        lbl_view_database_error->setObjectName("lbl_view_database_error");

        horizontalLayout->addWidget(lbl_view_database_error);


        verticalLayout_6->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_6, 0, 0, 4, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_3);

        tbl_transaction_history = new QTableWidget(centralwidget);
        if (tbl_transaction_history->columnCount() < 3)
            tbl_transaction_history->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl_transaction_history->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl_transaction_history->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbl_transaction_history->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tbl_transaction_history->setObjectName("tbl_transaction_history");

        verticalLayout_7->addWidget(tbl_transaction_history);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_err_transaction_history = new QLabel(centralwidget);
        lbl_err_transaction_history->setObjectName("lbl_err_transaction_history");

        verticalLayout->addWidget(lbl_err_transaction_history);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_14->addWidget(label_5);

        lnedit_act_number_transaction_history = new QLineEdit(centralwidget);
        lnedit_act_number_transaction_history->setObjectName("lnedit_act_number_transaction_history");

        horizontalLayout_14->addWidget(lnedit_act_number_transaction_history);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_10->addWidget(label_4);

        lnedit_num_of_counts_trans_history = new QLineEdit(centralwidget);
        lnedit_num_of_counts_trans_history->setObjectName("lnedit_num_of_counts_trans_history");

        horizontalLayout_10->addWidget(lnedit_num_of_counts_trans_history);


        verticalLayout->addLayout(horizontalLayout_10);

        pbn_view_transaction_history = new QPushButton(centralwidget);
        pbn_view_transaction_history->setObjectName("pbn_view_transaction_history");

        verticalLayout->addWidget(pbn_view_transaction_history);


        verticalLayout_7->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_7, 4, 0, 2, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_accountdeletion = new QLabel(centralwidget);
        lbl_accountdeletion->setObjectName("lbl_accountdeletion");
        lbl_accountdeletion->setFont(font);
        lbl_accountdeletion->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lbl_accountdeletion);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lbl_account_number_delete = new QLabel(centralwidget);
        lbl_account_number_delete->setObjectName("lbl_account_number_delete");

        horizontalLayout_7->addWidget(lbl_account_number_delete);

        lnedit_delete_account_number = new QLineEdit(centralwidget);
        lnedit_delete_account_number->setObjectName("lnedit_delete_account_number");

        horizontalLayout_7->addWidget(lnedit_delete_account_number);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        pbn_delete_account = new QPushButton(centralwidget);
        pbn_delete_account->setObjectName("pbn_delete_account");

        horizontalLayout_8->addWidget(pbn_delete_account);

        lbl_error_delete = new QLabel(centralwidget);
        lbl_error_delete->setObjectName("lbl_error_delete");

        horizontalLayout_8->addWidget(lbl_error_delete);


        verticalLayout_5->addLayout(horizontalLayout_8);


        gridLayout_2->addLayout(verticalLayout_5, 5, 1, 1, 2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        label_view_account_number = new QLabel(centralwidget);
        label_view_account_number->setObjectName("label_view_account_number");

        verticalLayout_4->addWidget(label_view_account_number);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_username = new QLabel(centralwidget);
        label_username->setObjectName("label_username");

        horizontalLayout_12->addWidget(label_username);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");

        horizontalLayout_12->addWidget(lineEdit_username);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        pushButton_get_account_number = new QPushButton(centralwidget);
        pushButton_get_account_number->setObjectName("pushButton_get_account_number");

        horizontalLayout_9->addWidget(pushButton_get_account_number);

        label_error = new QLabel(centralwidget);
        label_error->setObjectName("label_error");

        horizontalLayout_9->addWidget(label_error);


        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_7);

        lbl_viewbalance = new QLabel(centralwidget);
        lbl_viewbalance->setObjectName("lbl_viewbalance");

        verticalLayout_3->addWidget(lbl_viewbalance);

        label_error_viewbalance = new QLabel(centralwidget);
        label_error_viewbalance->setObjectName("label_error_viewbalance");

        verticalLayout_3->addWidget(label_error_viewbalance);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lbl_accountnumber = new QLabel(centralwidget);
        lbl_accountnumber->setObjectName("lbl_accountnumber");

        horizontalLayout_11->addWidget(lbl_accountnumber);

        lnedit_accountnumber = new QLineEdit(centralwidget);
        lnedit_accountnumber->setObjectName("lnedit_accountnumber");

        horizontalLayout_11->addWidget(lnedit_accountnumber);


        verticalLayout_4->addLayout(horizontalLayout_11);

        pbn_view_balance = new QPushButton(centralwidget);
        pbn_view_balance->setObjectName("pbn_view_balance");

        verticalLayout_4->addWidget(pbn_view_balance);


        gridLayout_2->addLayout(verticalLayout_4, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lbl_accountcreation = new QLabel(centralwidget);
        lbl_accountcreation->setObjectName("lbl_accountcreation");
        lbl_accountcreation->setFont(font);
        lbl_accountcreation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl_accountcreation, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_username_input = new QLabel(centralwidget);
        lbl_username_input->setObjectName("lbl_username_input");

        horizontalLayout_2->addWidget(lbl_username_input);

        lnedit_username_input = new QLineEdit(centralwidget);
        lnedit_username_input->setObjectName("lnedit_username_input");

        horizontalLayout_2->addWidget(lnedit_username_input);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_password = new QLabel(centralwidget);
        lbl_password->setObjectName("lbl_password");

        horizontalLayout_3->addWidget(lbl_password);

        lnedit_password_input = new QLineEdit(centralwidget);
        lnedit_password_input->setObjectName("lnedit_password_input");
        lnedit_password_input->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_3->addWidget(lnedit_password_input);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lbl_name = new QLabel(centralwidget);
        lbl_name->setObjectName("lbl_name");

        horizontalLayout_5->addWidget(lbl_name);

        lnedit_name_input = new QLineEdit(centralwidget);
        lnedit_name_input->setObjectName("lnedit_name_input");

        horizontalLayout_5->addWidget(lnedit_name_input);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_age = new QLabel(centralwidget);
        lbl_age->setObjectName("lbl_age");

        horizontalLayout_4->addWidget(lbl_age);

        lnedit_age_input = new QLineEdit(centralwidget);
        lnedit_age_input->setObjectName("lnedit_age_input");

        horizontalLayout_4->addWidget(lnedit_age_input);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        lbl_error_create = new QLabel(centralwidget);
        lbl_error_create->setObjectName("lbl_error_create");

        gridLayout->addWidget(lbl_error_create, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pbn_create_new_account = new QPushButton(centralwidget);
        pbn_create_new_account->setObjectName("pbn_create_new_account");

        horizontalLayout_6->addWidget(pbn_create_new_account);

        chkbox_admin = new QCheckBox(centralwidget);
        chkbox_admin->setObjectName("chkbox_admin");

        horizontalLayout_6->addWidget(chkbox_admin);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        horizontalLayout_15->addWidget(label_6);

        lnedit_update_acc_num = new QLineEdit(centralwidget);
        lnedit_update_acc_num->setObjectName("lnedit_update_acc_num");

        horizontalLayout_15->addWidget(lnedit_update_acc_num);


        verticalLayout_2->addLayout(horizontalLayout_15);

        pbn_update_account = new QPushButton(centralwidget);
        pbn_update_account->setObjectName("pbn_update_account");

        verticalLayout_2->addWidget(pbn_update_account);


        gridLayout->addLayout(verticalLayout_2, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 4, 2, 1, 1);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 781, 21));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "Bank Data Base", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl_view_database->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminWindow", "AccountNumber", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl_view_database->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl_view_database->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl_view_database->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminWindow", "Balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl_view_database->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdminWindow", "Age", nullptr));
        pbn_view_database->setText(QCoreApplication::translate("AdminWindow", "View Database", nullptr));
        lbl_view_database_error->setText(QString());
        label_3->setText(QCoreApplication::translate("AdminWindow", "Transaction History", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl_transaction_history->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AdminWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl_transaction_history->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AdminWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl_transaction_history->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AdminWindow", "Time", nullptr));
        lbl_err_transaction_history->setText(QString());
        label_5->setText(QCoreApplication::translate("AdminWindow", "Account Number :", nullptr));
        label_4->setText(QCoreApplication::translate("AdminWindow", "Counts :                  ", nullptr));
        pbn_view_transaction_history->setText(QCoreApplication::translate("AdminWindow", "View Transaction history", nullptr));
        lbl_accountdeletion->setText(QCoreApplication::translate("AdminWindow", "Delete Account", nullptr));
        lbl_account_number_delete->setText(QCoreApplication::translate("AdminWindow", "Account Number:   ", nullptr));
        pbn_delete_account->setText(QCoreApplication::translate("AdminWindow", "Delete Account", nullptr));
        lbl_error_delete->setText(QString());
        label_2->setText(QCoreApplication::translate("AdminWindow", "Account Number", nullptr));
        label_view_account_number->setText(QCoreApplication::translate("AdminWindow", "Account Number: ", nullptr));
        label_username->setText(QCoreApplication::translate("AdminWindow", "username:", nullptr));
        pushButton_get_account_number->setText(QCoreApplication::translate("AdminWindow", "Get Account Number", nullptr));
        label_error->setText(QString());
        label_7->setText(QCoreApplication::translate("AdminWindow", "View Account Balance", nullptr));
        lbl_viewbalance->setText(QCoreApplication::translate("AdminWindow", "Balance:", nullptr));
        label_error_viewbalance->setText(QString());
        lbl_accountnumber->setText(QCoreApplication::translate("AdminWindow", "Account Number: ", nullptr));
        pbn_view_balance->setText(QCoreApplication::translate("AdminWindow", "View Balance", nullptr));
        lbl_accountcreation->setText(QCoreApplication::translate("AdminWindow", "Create / Update Account", nullptr));
        lbl_username_input->setText(QCoreApplication::translate("AdminWindow", "Username: ", nullptr));
        lbl_password->setText(QCoreApplication::translate("AdminWindow", "Password:  ", nullptr));
        lbl_name->setText(QCoreApplication::translate("AdminWindow", "Name:        ", nullptr));
        lbl_age->setText(QCoreApplication::translate("AdminWindow", "Age:            ", nullptr));
        lbl_error_create->setText(QString());
        pbn_create_new_account->setText(QCoreApplication::translate("AdminWindow", "Create New Account", nullptr));
        chkbox_admin->setText(QCoreApplication::translate("AdminWindow", "Admin", nullptr));
        label_6->setText(QCoreApplication::translate("AdminWindow", "Account Number:", nullptr));
        pbn_update_account->setText(QCoreApplication::translate("AdminWindow", "Update Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
