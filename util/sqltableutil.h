/*
 * @Description: Table
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 00:48:00
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:12:18
 * @FilePath: /util/sqltableutil.h
 */

#ifndef SQLTABLEUTIL_H
#define SQLTABLEUTIL_H

#include <QSqlQuery>
#include <QVariantList>
#include <QSqlError>
#include <QVector>
#include <QDebug>

class SqlTableUtil
{

public:
    SqlTableUtil();
    QString tableName = "";

    QSqlQuery query;


    /**
     * @description: 执行和操作的SQL语句
     * @param {type}
     * @return:
     */
    bool query_exec(const QString &str) {
        qDebug() << str;
        query.prepare(str);
        if(!query.exec()) {
            QSqlError error  =  query.lastError();
            if(error.isValid()) {
                switch (error.type()) {
                    case QSqlError::NoError:
                        qDebug() << "无错误";
                        break;
                    case QSqlError::ConnectionError: //连接错语
                        qDebug() << "ConnectionError";
                        break;
                    case QSqlError::StatementError:  //语句错语
                        qDebug() << "StatementError";
                        break;
                    case QSqlError::TransactionError://事务错误
                        qDebug() << "TransactionError";
                        break;
                    default://未知错误
                        break;
                }
                qDebug() << error.text();
            }
            return false;
        }
        return true;
    }

public:
    /**
     * @description: 创建表
     * @param {type}
     * @return:
     */
    bool create(const QString &tableName) {
        QString str = QString("CREATE TABLE IF NOT EXISTS %1 ("
                            "id INTEGER PRIMARY KEY, "  //AUTOINCREMENT
                            "name VARCHAR(10), "        //TEXT
                            "price VARCHAR(8), "        //FLOAT
                            "bp VARCHAR(10), "          //BIGINT
                            "state CHAR, "
                            "time VARCHAR(32),"
                            "url VARCHAR(100))").arg(tableName);//TIMESTAMP  DATETIME
        return query_exec(str);
    }

    /**
     * @description: 清空表
     * @param {type}
     * @return:
     */
    bool clear() {
        return query_exec(QString("delete from %1").arg(tableName));
    }

    /**
     * @description: 删除记录
     * @param {type}
     * @return:
     */
    bool delete_record(const int &id) {
        QString str = QString("delete from %1 where id = %2").arg(tableName, QString::number(id));;
        return query_exec(str);
    }

    /**
     * @description: 是否存在ID
     * @param {type}
     * @return:
     */
    bool is_exists_id(const int &id) {
        QString str = QString("select id from %1 where id = %2").arg(tableName, QString::number(id));
        if(query_exec(str)&&query.next()) {
            return true;
        }
        return false;
    }

    /**
     * @description: 插入数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _insert(const T &t) {
        return true;
    }

    /**
     * @description: 删除数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _delete(const T &t) {
        return true;
    }

    /**
     * @description: 更新数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _update(const T &t) {
        return true;
    }

    /**
     * @description: 查询数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _select(const T &t) {
        return true;
    }

};

#endif // SQLTABLEUTIL_H