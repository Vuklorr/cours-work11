#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

bool connection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("test");
    db.setPassword("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");
    db.setDatabaseName("5Al");
    if(!db.open()) {
        QMessageBox::critical(nullptr,"Ошибка в подключении БД!",
                              "Не удалось подключится к базе данных. Проверьте корректность подключения",
                              QMessageBox::Cancel);
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!connection()) {
        exit(0);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
