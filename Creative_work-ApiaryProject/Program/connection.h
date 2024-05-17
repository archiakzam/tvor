#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

inline bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("85.193.89.100");
    db.setDatabaseName("beez");
    db.setUserName("arduino");
    db.setPassword("sRYdkp!cftI8MmN8");
    db.open();
    if(db.open()){
        QMessageBox::information(0, "Успешно", "Соединение с БД/установлено!");
        return true;
    }
    else{

        QMessageBox::warning(0, "Нет соединения", db.lastError().text());
        return false;
    }

}

#endif // CONNECTION_H
