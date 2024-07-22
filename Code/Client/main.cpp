
#include <QApplication>
#include "mainwindow.h"
#include "userwindow.h"
#include "adminwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Login_Window;
    Login_Window.show();

    // UserWindow user;
    // user.show();

    // AdminWindow admin;
    // admin.show();

    return a.exec();
}
