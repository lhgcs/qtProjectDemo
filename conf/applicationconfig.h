/*
 * @Description: 应用配置文件
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-13 17:36:28
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 17:40:51
 * @FilePath: /conf/applicationconfig.h
 */

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include <QSettings> 
#include <QDir> 
#include <QFile> 
#include <QApplication> 
#include <QCoreApplication> 
#include <QFontDatabase> 
#include <QFont> 

#include <QDebug> 
#define LOG qDebug() << __FILE__ << __FUNCTION__ << __LINE__

class ApplicationConfig {

public:
    ApplicationConfig();

    static QString applicationPath;
    static QString applicationName;

    static QString ip;
    static int port;

     /**
     * @description: 读取配置文件
     * @param {type}
     * @return:
     */
    void read_config() {
        QString fileName = QString("%1/%2_Config.ini").arg(applicationPath).arg(applicationName);

        //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
        QFile file(fileName);
        if (file.size() =  = 0) {
            write_config();
            return;
        }

        QSettings set(fileName, QSettings::IniFormat);
        set.beginGroup("AppConfig");
        ip = set.value("ip").toString();
        port = set.value("port").toInt();
        set.endGroup();
    }

     /**
     * @description: 写配置文件
     * @param {type}
     * @return:
     */
    void write_config() {
        QString fileName = QString("%1/%2_Config.ini").arg(applicationPath).arg(applicationName);

        QSettings set(fileName, QSettings::IniFormat);
        set.beginGroup("AppConfig");
        ip = set.value("ip").toString();
        port = set.value("port").toInt();
        set.endGroup();
    }

    /**
     * @description: 查找文件
     * @param {type}
     * @return:
     */
    static QStringList find_file(const QString dirName, const QStringList fileFilter) {
        QDir dir(dirName);
        if(dir.exists()) {
            QStringList res = dir.entryList(fileFilter);
            return res;
        }
    }

    /**
     * @description: 设置字体
     * @param {type}
     * @return:
     */
    static void set_font(QApplication &application) {
        QString dirName = "/home/font";
        QStringList fileFilter;
        fileFilter << "*.ttf" << "*.ttc";

        QStringList res = find_file(dirName, fileFilter);
        if(res.size() > 0) {
            // 将字体文件名传给addApplicationFont,得到字体的Id
            int index = QFontDatabase::addApplicationFont(dirName + "/" + res.at(0));
            if(index != -1) {
                // 将字体Id传给applicationFontFamilies,得到一个QStringList,其中的第一个元素为新添加字体的family
                QStringList strList(QFontDatabase::applicationFontFamilies(index));
                if(strList.count() > 0) {
                    QFont fontThis(strList.at(0));
                    fontThis.setBold(false);
                    fontThis.setPointSize(24);
                    application.setFont(fontThis);
                }
            } else {
                printf("system fnot error!!!\n");
            }
        }
    }

    /**
     * @description: 设置QSS样式
     * @param {type}
     * @return:
     */
    static void set_qss(const QString path) {
        QFile qss(path);
        if(qss.open(QFile::ReadOnly)) {
            qApp->setStyleSheet(qss.readAll());
            qss.close();
        }
    }

    /**
     * @description: 重启
     * @param {type}
     * @return:
     */
    static void reboot() {
        QCoreApplication::processEvents();
        system("reboot");
    }

};

QString ApplicationConfig::applicationPath = "";
QString ApplicationConfig::applicationName = "";
QString ApplicationConfig::ip = "127.0.0.1";
int ApplicationConfig::port = 80;

#endif // APPLICATIONCONFIG_H