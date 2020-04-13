/*
 * @Description: http请求
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-12 23:49:15
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:09:04
 * @FilePath: /util/httputil.h
 */

#ifndef HTTPUTIL_H
#define HTTPUTIL_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include <QUrlQuery>
#include <QMap>
#include <QNetworkReply>

class HttpUtil
{
public:
    HttpUtil();
    QNetworkAccessManager *manager;

    /**
     * @description: get请求
     * @param {type}
     * @return:
     */
    void get(const QString url) {
        manager->get(QNetworkRequest(QUrl(url)));
    }

    /**
     * @description: get请求
     * @param {type} 
     * @return: 
     */
    template <class T>
    void get(const QString url, QMap<QString, T> map) {
        QUrlQuery query;
        QMap<int, int>:: iterator it = map.constBegin();
        for (; it != map.constEnd(); it++) {
            query.addQueryItem(it.key(), key.value());
        }
        QUrl _url;
        _url.setQuery(query);
        manager->get(QNetworkRequest(QUrl(_url)));
    }

    /**
     * @description: 下载文件
     * @param {type}
     * @return:
     */
    static bool download(const QString &url, QByteArray &data, int time_ms = 5000) {
        bool res = false;
        qDebug() << url;
        QNetworkAccessManager manager;
        QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(url)));
        QEventLoop eventLoop;
        QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

        QTimer timer;
        timer.setSingleShot(true);
        QObject::connect(&timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));
        timer.start(time_ms);
        eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

        if(timer.isActive()) {
            timer.stop();
            if(reply->error() == QNetworkReply::NoError) {
                data = reply->readAll();  //UTF-8编码
                res = true;
            } else {
                qDebug() << "load failed:" << reply->error();
            }
        } else {
            qDebug() << "load time out";
        }

        QObject::disconnect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

        reply->abort();
        reply->close();
        reply->deleteLater();//并没有将对象立即销毁，而是向主消息循环发送了一个event，下一次主消息循环收到这个event之后才会销毁对象
        reply = NULL;
        return res;
    }

//manager = new QNetworkAccessManager(this);//创建一个管理器
//QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    /**
     * @description: 数据处理
     * @param {type}
     * @return:
     */
    void replyFinished(QNetworkReply* reply) {
        QByteArray byte = reply->readAll();
        qDebug() << byte;
        if(byte.isEmpty()) {
            return;
        }
    }

};

#endif // HTTPUTIL_H