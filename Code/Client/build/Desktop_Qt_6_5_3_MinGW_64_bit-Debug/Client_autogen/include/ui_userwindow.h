/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_title_trasnaction;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_amount;
    QLineEdit *lnedit_amount;
    QLabel *lbl_transaction_error;
    QPushButton *pbn_make_trasnaction;
    QLabel *lbl_transfe_amout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_to_acc_no;
    QLineEdit *lnedit_to_accountnumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_trnsfr_amnt;
    QLineEdit *lnedit_trnsfr_amount;
    QLabel *lbl_mk_trnsf_err;
    QPushButton *pbn_mk_transfer;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_Account_Balance;
    QLabel *label_view_balance;
    QPushButton *pbn_view_balance;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_account_number;
    QPushButton *pushButton_get_account_number;
    QVBoxLayout *verticalLayout_6;
    QLabel *lbl_view_trnsction_history;
    QTableWidget *tbl_view_histroy_transaction;
    QLabel *lbl_err_transaction_history;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbn_view_transaction_histroy;
    QLineEdit *lnedit_num_of_counts_trans_history;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(844, 498);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_title_trasnaction = new QLabel(centralwidget);
        lbl_title_trasnaction->setObjectName("lbl_title_trasnaction");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        font.setBold(true);
        lbl_title_trasnaction->setFont(font);
        lbl_title_trasnaction->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lbl_title_trasnaction);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_amount = new QLabel(centralwidget);
        lbl_amount->setObjectName("lbl_amount");

        horizontalLayout_2->addWidget(lbl_amount);

        lnedit_amount = new QLineEdit(centralwidget);
        lnedit_amount->setObjectName("lnedit_amount");

        horizontalLayout_2->addWidget(lnedit_amount);


        verticalLayout_3->addLayout(horizontalLayout_2);

        lbl_transaction_error = new QLabel(centralwidget);
        lbl_transaction_error->setObjectName("lbl_transaction_error");

        verticalLayout_3->addWidget(lbl_transaction_error);

        pbn_make_trasnaction = new QPushButton(centralwidget);
        pbn_make_trasnaction->setObjectName("pbn_make_trasnaction");

        verticalLayout_3->addWidget(pbn_make_trasnaction);

        lbl_transfe_amout = new QLabel(centralwidget);
        lbl_transfe_amout->setObjectName("lbl_transfe_amout");
        lbl_transfe_amout->setFont(font);
        lbl_transfe_amout->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lbl_transfe_amout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_to_acc_no = new QLabel(centralwidget);
        lbl_to_acc_no->setObjectName("lbl_to_acc_no");

        horizontalLayout_3->addWidget(lbl_to_acc_no);

        lnedit_to_accountnumber = new QLineEdit(centralwidget);
        lnedit_to_accountnumber->setObjectName("lnedit_to_accountnumber");

        horizontalLayout_3->addWidget(lnedit_to_accountnumber);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_trnsfr_amnt = new QLabel(centralwidget);
        lbl_trnsfr_amnt->setObjectName("lbl_trnsfr_amnt");

        horizontalLayout_4->addWidget(lbl_trnsfr_amnt);

        lnedit_trnsfr_amount = new QLineEdit(centralwidget);
        lnedit_trnsfr_amount->setObjectName("lnedit_trnsfr_amount");

        horizontalLayout_4->addWidget(lnedit_trnsfr_amount);


        verticalLayout_3->addLayout(horizontalLayout_4);

        lbl_mk_trnsf_err = new QLabel(centralwidget);
        lbl_mk_trnsf_err->setObjectName("lbl_mk_trnsf_err");

        verticalLayout_3->addWidget(lbl_mk_trnsf_err);

        pbn_mk_transfer = new QPushButton(centralwidget);
        pbn_mk_transfer->setObjectName("pbn_mk_transfer");

        verticalLayout_3->addWidget(pbn_mk_transfer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_Account_Balance = new QLabel(centralwidget);
        lbl_Account_Balance->setObjectName("lbl_Account_Balance");
        lbl_Account_Balance->setFont(font);
        lbl_Account_Balance->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbl_Account_Balance);

        label_view_balance = new QLabel(centralwidget);
        label_view_balance->setObjectName("label_view_balance");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_view_balance->setFont(font1);

        verticalLayout_2->addWidget(label_view_balance);

        pbn_view_balance = new QPushButton(centralwidget);
        pbn_view_balance->setObjectName("pbn_view_balance");

        verticalLayout_2->addWidget(pbn_view_balance);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_account_number = new QLabel(centralwidget);
        label_account_number->setObjectName("label_account_number");

        verticalLayout->addWidget(label_account_number);

        pushButton_get_account_number = new QPushButton(centralwidget);
        pushButton_get_account_number->setObjectName("pushButton_get_account_number");

        verticalLayout->addWidget(pushButton_get_account_number);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 3, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lbl_view_trnsction_history = new QLabel(centralwidget);
        lbl_view_trnsction_history->setObjectName("lbl_view_trnsction_history");
        lbl_view_trnsction_history->setFont(font);
        lbl_view_trnsction_history->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lbl_view_trnsction_history);

        tbl_view_histroy_transaction = new QTableWidget(centralwidget);
        if (tbl_view_histroy_transaction->columnCount() < 3)
            tbl_view_histroy_transaction->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl_view_histroy_transaction->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl_view_histroy_transaction->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl_view_histroy_transaction->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tbl_view_histroy_transaction->setObjectName("tbl_view_histroy_transaction");

        verticalLayout_6->addWidget(tbl_view_histroy_transaction);


        gridLayout->addLayout(verticalLayout_6, 0, 1, 1, 1);

        lbl_err_transaction_history = new QLabel(centralwidget);
        lbl_err_transaction_history->setObjectName("lbl_err_transaction_history");

        gridLayout->addWidget(lbl_err_transaction_history, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbn_view_transaction_histroy = new QPushButton(centralwidget);
        pbn_view_transaction_histroy->setObjectName("pbn_view_transaction_histroy");

        horizontalLayout->addWidget(pbn_view_transaction_histroy);

        lnedit_num_of_counts_trans_history = new QLineEdit(centralwidget);
        lnedit_num_of_counts_trans_history->setObjectName("lnedit_num_of_counts_trans_history");

        horizontalLayout->addWidget(lnedit_num_of_counts_trans_history);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 844, 21));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName("statusbar");
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        lbl_title_trasnaction->setText(QCoreApplication::translate("UserWindow", "Transaction", nullptr));
        lbl_amount->setText(QCoreApplication::translate("UserWindow", "Amount: ", nullptr));
        lbl_transaction_error->setText(QString());
        pbn_make_trasnaction->setText(QCoreApplication::translate("UserWindow", "Make a Transaction", nullptr));
        lbl_transfe_amout->setText(QCoreApplication::translate("UserWindow", "Transfer To Account", nullptr));
        lbl_to_acc_no->setText(QCoreApplication::translate("UserWindow", "To Account Number :    ", nullptr));
        lbl_trnsfr_amnt->setText(QCoreApplication::translate("UserWindow", "Transfer Amount (EGP): ", nullptr));
        lbl_mk_trnsf_err->setText(QString());
        pbn_mk_transfer->setText(QCoreApplication::translate("UserWindow", "Transfer", nullptr));
        lbl_Account_Balance->setText(QCoreApplication::translate("UserWindow", "Account Balance", nullptr));
        label_view_balance->setText(QString());
        pbn_view_balance->setText(QCoreApplication::translate("UserWindow", "View Account Balance", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Account Number", nullptr));
        label_account_number->setText(QString());
        pushButton_get_account_number->setText(QCoreApplication::translate("UserWindow", "Get Account Number", nullptr));
        lbl_view_trnsction_history->setText(QCoreApplication::translate("UserWindow", "Transaction History", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl_view_histroy_transaction->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl_view_histroy_transaction->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UserWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl_view_histroy_transaction->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        lbl_err_transaction_history->setText(QString());
        pbn_view_transaction_histroy->setText(QCoreApplication::translate("UserWindow", "View History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
