#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dataname = "D:/QtTest/mvc/sqllite";
    if (!conncection(dataname)) {
         QMessageBox::information(nullptr, "Open DataBase!", "failed");
    }

    MainWindow w;
    w.show();

    return a.exec();
}
