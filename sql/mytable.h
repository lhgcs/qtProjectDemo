/*
 * @Description: 具体表
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 17:47:00
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 17:47:01
 * @FilePath: /sql/mytable.h
 */

#ifndef MYTABLE_H
#define MYTABLE_H

#include "util/sqltableutil.h"

class MyTable : SqlTableUtil
{
public:
    MyTable();

    /**
     * @description: 插入数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _insert(const T &t) {

    }

    /**
     * @description: 删除数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _delete(const T &t) {

    }

    /**
     * @description: 更新数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _update(const T &t) {

    }

    /**
     * @description: 查询数据
     * @param {type}
     * @return:
     */
    template <class T>
    bool _select(const T &t) {
        QList<T> res;
        if(query_exec(QString("select name,price,bp,state from %1 where %2").arg(tableName, t)) {
            query.size();
            if(query.next()) {
                T temp;
                res.append(temp);
//                name =query.value("name").toString();
//                price=query.value("price").toFloat();
//                bp   =query.value("bp").toULongLong();//705032704
//                state=query.value("state").toInt();
                return true;
            }
        }
        return res;
    }

//    {
//        QString str=QString("INSERT INTO %1 (id,name,price,bp,state,time,url) "
//                            "VALUES (\'%2\',\'%3\',\'%4\',\'%5\',\'%6\',\'%7\',\'%8\')")
//                            .arg(tableName,id,name,price,BP,state,time,url);
//        return query_exec(str);
//    }

            // QString str=QString("update %1 set name=\'%2\',price=\'%3\',bp=\'%4\',state=\'%5\',time=\'%6\',url=\'%7\' where id=%8")
            //                     .arg(tableName,name,price,bp,state,time,url,id);
};

#endif // MYTABLE_H
