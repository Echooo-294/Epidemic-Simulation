/*
 * @Description: 居民类的声明
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-04 21:09
 */

#ifndef RESIDENT_H
#define RESIDENT_H

#include <QObject>

class Resident : public QObject
{
    Q_OBJECT
public:
    explicit Resident(QObject *parent = nullptr);
    double getHealthStatus();
    int getActivityStatus();
private:
    double healthStatus;//健康状态（健康、感染潜伏、感染出症状、重症、死亡）取决于病毒密度
    int activityStatus;//活动状态（自由活动0、密切接触1、独立隔离2、确诊3、治疗中4、治愈5）

signals:

};

#endif // RESIDENT_H
