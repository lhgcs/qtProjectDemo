/*
 * @Description: Database
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-12 23:43:37
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:11:01
 * @FilePath: /util/sqldatabaseutil.h
 */

#ifndef SQLDATABASEUTIL_H
#define SQLDATABASEUTIL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QStringList>
#include <QDebug>

class SqlDatabaseUtil
{
public:
    SqlDatabaseUtil();

private:
    QString dbName = "";

    /**
     * @description: 创建数据库
     * @param {type}
     * @return:
     */
    bool create(const QString &dbName) {
        QStringList drivers=QSqlDatabase::drivers();
        qDebug()<<drivers;
        if(!drivers.contains("QSQLITE",Qt::CaseInsensitive)) {
            qDebug()<<"SQLITE not have QSQLITE drivers";
            return false;
        }

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);
        if(!db.open()) {
            qDebug() << "Database Error: "<< db.lastError();
            return false;
        }
        return true;
    }

};

#endif // SQLDATABASEUTIL_H