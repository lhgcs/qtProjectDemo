/*
 * @Description: 应用程序基类
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 18:13:17
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:13:35
 * @FilePath: /widget/baseapplication.h
 */

#ifndef BASEAPPLICATION_H
#define BASEAPPLICATION_H

#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>

class BaseApplication : QApplication
{
public:
    BaseApplication(int &argc,char **argv);

    bool notify(QObject *obj, QEvent *e) {
        const QMetaObject* objMeta = obj->metaObject();
        QString clName = objMeta->className();

        if(e->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
            if(keyEvent->key() == Qt::Key_F1) {

            }
            // widget->keyPress(keyEvent);
        } else if(e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(e);
            if(mouseEvent->buttons() == Qt::LeftButton) {

            }
        }
        return QApplication::notify(obj,e);
    }

};

#endif // BASEAPPLICATION_H