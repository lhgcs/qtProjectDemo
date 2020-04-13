/*
 * @Description: 文件工具类
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-12 23:56:31
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:03:58
 * @FilePath: /util/fileutil.h
 */

#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QFile>
#include <QTextStream>

class FileUtil
{
public:
    FileUtil();

    /**
     * @description: 读文件
     * @param {type}
     * @return:
     */
    static QString readFile(const QString &filePath) {
        QFile file(filePath);
        QString line = "";

        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                line = in.readLine();
            }
            file.close();
        }

        return line;
    }

    /**
     * @description: 写文件
     * @param {type}
     * @return:
     */
    static void writeFile(const QString &filePath, const QString &str) {
        QFile file(filePath);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << str << "\n";
            file.close();
        }
    }

    /**
     * @description: 读文件
     * @param {type}
     * @return:
     */
    static QString readFile2(const QString &filePath) {
        QFile file(filePath);
        QString line = "";

        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            file.readAll();
            file.close();
        }

        return line;
    }

    /**
     * @description: 写文件
     * @param {type}
     * @return:
     */
    static void writeFile2(const QString &filePath, const QString &str) {
        QFile file(filePath);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.write(str.toUtf8());
            file.close();
        }
    }

    /**
     * @description: 写文件
     * @param {type}
     * @return:
     */
    static void writeFile2(const QString &filePath, const QByteArray &byte) {
        QFile file(filePath);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.write(byte);
            file.close();
        }
    }

    /**
     * @description: 创建多级目录
     * @param {type} 
     * @return: 
     */
    static void create_dir(QString dirPath) {
        if(dirPath.endsWith("/")){
            dirPath.chop(1);
        }
        QDir dir(dirPath);
        if(!dir.exists()) {
            dir.mkpath(dirPath);
        }
    }

    /**
     * @description: 文件是否存在
     * @param {type} 
     * @return: 
     */
    static bool is_file_exits(const QString &filePath){
        QFileInfo file_info(filePath);
        return file_info.isFile();
    }

    /**
     * @description: 创建文件
     * @param {type} 
     * @return: 
     */
    static void create_file(const QString &filePath) {
        if(is_file_exits(filePath)) {
            QFile file(filePath);
            file.open(QIODevice::WriteOnly);
            file.close();
        }
    }

    /**
     * @description: 删除文件
     * @param {type} 
     * @return: 
     */
    static void remove_file(const QString &filePath) {
        if(is_file_exits(filePath)) {
            QFile::remove(filePath);
        }
    }

    static void clear_dir(const QString &dirPath) {
        QDir dir(dirPath);
        dir.setFilter(QDir::Files);
        int fileCount = dir.count();
        for (int i = 0; i < fileCount; i++) {
            dir.remove(dir[i]);
        }
    }

};

#endif // FILEUTIL_H