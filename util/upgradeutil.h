/*
 * @Description: 升级
 * @Version: 1.0
 * @Autor: lhgcs
 * @Date: 2020-04-12 23:53:42
 * @LastEditors: lhgcs
 * @LastEditTime: 2020-04-13 18:12:46
 * @FilePath: /util/upgradeutil.h
 */

#ifndef UPGRADEUTIL_H
#define UPGRADEUTIL_H

#include <QString>

class UpgradeUtil
{
public:
    UpgradeUtil();

    /**
     * @description: 获取日期
     * @param {type}
     * @return:
     */
    int get_datetime() {
        unsigned char temp_str[4] = {};
        unsigned int year = 0;
        unsigned int month = 0;
        unsigned int date = 0;
        char currentTime[64];
        const unsigned char monthStr[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov","Dec"};

        sscanf(__DATE__, "%s %d %d", temp_str, &date, &year);

        for(int i=0; i<12; i++) {
            if(temp_str[0] == monthStr[i][0] && temp_str[1] == monthStr[i][1] && temp_str[2] == monthStr[i][2]) {
                month = i + 1;
                break;
            }
        }

        sprintf(currentTime, "%04d%02d%02d", year, month, date);
        return 0;
    }

    /**
     * @description: 比较版本
     * @param {type}
     * @return:
     */
    int compare_version(const QString &nowVersion, const QString &serverVersion) {
        int _now[3] = {0};
        int _server[3] = {0};
        char _nowStr[10];
        char _serverStr[10];

        char *_nowVersion = nowVersion.toUtf8().data();
        char *_serverVersion = serverVersion.toUtf8().data();

        sscanf(_nowVersion, "V%d.%d.%d_%s", _now + 0, _now + 1, _now + 2, _nowStr);
        sscanf(_serverVersion, "V%d.%d.%d_%s", _server + 0, _server + 1, _server + 2, _serverStr);

        for(int i=0; i<3; i++) {
            if(_now[i] < _server[i]) {
                return 1;
            }
        }
        return 0;
    }
};

#endif // UPGRADEUTIL_H