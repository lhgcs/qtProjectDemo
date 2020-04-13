/*
 * @Description: 对话框
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 17:33:02
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:24:52
 * @FilePath: /widget/dialoginstance.h
 */

#ifndef DIALOGINSTANCE_H
#define DIALOGINSTANCE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStyleOption>
#include <QPainter>
#include <QTimer>
#include <QVBoxLayout>

class DialogInstance : public QWidget
{
    Q_OBJECT
public:
    explicit DialogInstance(QWidget *parent = 0);
    ~DialogInstance() {
        delete timer;
        delete label;
        delete button;
        delete vl;
    }

    /**
     * @description: 获取对话框
     * @param {type} 
     * @return: 
     */
    static DialogInstance* getInstance() {
         if( instan == NULL )
             instan = new DialogInstance();
         return instan;
    }
    static DialogInstance* getInstance(QString str, int _ms=5000, QWidget *parent =0) {
         if( instan == NULL ) {
             instan = new DialogInstance(parent);
         }
         instan->setText(str,_ms);
         return instan;
    }
    void setText(QString str,int _ms=5000) {
        if(str != NULL) {
            label->setText(str);
            this->setVisible(true);
            this->raise();
            if(_ms>0) {
                timer->start(_ms);
            }
            else {
                timer->stop();
            }
        }
    }
    void close() {
        timer->stop();
        this->hide();
    }
private:
    static DialogInstance * instan;
    QVBoxLayout *vl;
    void move_to_centre() {
    }
private:
    QLabel *label;
    QPushButton *button;
    QTimer *timer;
};

#endif // DIALOGINSTANCE_H