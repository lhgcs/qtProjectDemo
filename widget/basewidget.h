/*
 * @Description: 窗口基类
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 00:46:46
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:20:26
 * @FilePath: /widget/basewidget.h
 */

#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QPixmap>

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = 0);

    /**
     * @description: 设置窗口的背景图
     * @param {type} 
     * @return: 
     */
    void set_background_image(const QString &imagePath) {
        QPixmap pixmap(imagePath);
        QPalette palette = this->palette();
        palette.setBrush(this->backgroundRole(), QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        this->setPalette(palette);
    }

    /**
     * @description: 设置窗口的背景色
     * @param {type} 
     * @return: 
     */
    void set_background_image(const QString &imagePath) {
        QPixmap pixmap(imagePath);
        QPalette palette = this->palette();
        palette.setBrush(QPalette::Background,QBrush(Qt::red));
        this->setPalette(palette);
    }

signals:

public slots:

protected:
    /**
     * @description: 
     * @param {type} 
     * @return: 
     */
    void paintEvent(QPaintEvent *){
        QStyleOption option;
        option.init(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
    }
};

#endif // BASEWIDGET_H