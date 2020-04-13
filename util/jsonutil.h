/*
 * @Description: json
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-12 23:40:03
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:09:25
 * @FilePath: /util/jsonutil.h
 */

#ifndef JSONUTIL_H
#define JSONUTIL_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QDebug>

class JsonUtil
{
public:
    JsonUtil();

    /**
     * @description: 是否包含字段
     * @param {type}
     * @return:
     */
    static bool is_contain_key(const QJsonObject &object, const QString &key) {
        return object.contains(key) ? true : false;
    }

    /**
     * @description: 解析字符串
     * @param {type}
     * @return:
     */
    static bool parse(const QByteArray &byte, QJsonObject &obj) {
        QString str = QString(byte);
        QJsonDocument jsonDocument;

        if(parse(str, jsonDocument)) {
            if(jsonDocument.isObject()) {   //一个对象
                obj =jsonDocument.object();//取得最外层这个大对象
                return true;
            }
        }
        return false;
    }

    /**
     * @description: 解析字符串
     * @param {type}
     * @return:
     */
    static bool parse(const QString &str, QJsonDocument &jsonDocument) {
        QJsonParseError error;
        jsonDocument = QJsonDocument::fromJson(str.toUtf8(), &error);
        if(error.error == QJsonParseError::NoError) {
            if(jsonDocument.isNull() || jsonDocument.isEmpty()) {
                qDebug()<<"json NULL";
            } else {
                return true;
            }
        } else {
            qDebug()<<"json error: "<<error.error;
        }
        return false;
    }

    /**
     * @description: 获取对象
     * @param {type}
     * @return:
     */
    static bool parse(const QJsonDocument &jsonDocument, const QString &key,QJsonValue &json_value) {
        if(jsonDocument.isObject()) {                //一个对象
            QJsonObject obj = jsonDocument.object();//取得最外层这个大对象
            if(obj.contains(key)) {                  //如果包含key,进行取值
                json_value = obj.take(key);
                return true;
            }
        }
        return false;
    }

    /**
     * @description: 获取键值
     * @param {type}
     * @return:
     */
    template <class T>
    static bool get_value(QJsonObject &object, const QString &key, T &t) {
        bool res = true;
        if (object.contains(key)) {
            QJsonValue value = object.take(key);
            if (value.isBool()) {
                t = value.toBool();
            } else if(value.isDouble()) {
                t = value.toDouble();
            } else if(value.isString()) {
                t = value.toString();
            } else if(value.isArray()) {
                t = value.toArray();
            } else if(value.isObject()) {
                t = value.toObject();
            } else {
                res = false;
            }
        } else {
            res = false;
        }
        return res;
    }

    /**
     * @description: 获取键值
     * @param {type}
     * @return:
     */
    template <class T>
    static bool get_value(const QJsonValue &value, T &t) {
        bool res = true;
        if(value.type() == QJsonValue::Bool) {
            t = value.toBool();
        } else if(value.type()==QJsonValue::Double) {
            t = value.toDouble();
        } else if(value.type()==QJsonValue::String) {
            t = value.toString();
        } else if(value.type()==QJsonValue::Array) {
            t = value.toArray();
        } else if(value.type()==QJsonValue::Object) {
            t = value.toObject();
        } else {
            res = false;
        }
        return res;
    }

    /**
     * @description: json转字符串
     * @param {type}
     * @return:
     */
    static QString to_string(const QJsonObject &json) {
        QJsonDocument document;
        document.setObject(json);
        QByteArray byte = document.toJson(QJsonDocument::Compact);
        QString str(byte);
        return str;
    }

    static QString to_string(const QJsonArray &json) {
        QJsonDocument document;
        document.setArray(json);
        QByteArray byte = document.toJson(QJsonDocument::Compact);
        QString str(byte);
        return str;
    }

    /**
     * @description: 构建 Json 数组
     * @param {type}
     * @return:
     */
    static void json_array_add(QJsonArray &array,const QJsonObject &obj) {
        array.append(obj);
    }

    /**
     * @description: 构建 Json 对象
     * @param {type}
     * @return:
     */
    static void json_object_add(QJsonObject &obj,const QString &key,const QString &value) {
        obj.insert(key, QJsonValue(value));
    }

};

#endif // JSONUTIL_H