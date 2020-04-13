#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}


/*


  MainWindow *main=new MainWindow;//项目主窗口
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsProxyWidget *w = scene->addWidget(main);
    w->setRotation(90);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setFixedSize(HEIGHT,WIDTH);
    view->show();
    main->init();

    */
