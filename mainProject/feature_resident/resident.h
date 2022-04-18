/*
 * @Description: 居民类的声明
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-18
 */

#ifndef RESIDENT_H
#define RESIDENT_H

#include <QObject>
#include <QPoint>
#include <QTime>
#include<feature_virus/virus.h>
#include<QGraphicsEllipseItem>

class Resident : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit Resident(QObject *parent = nullptr,double im=1.0);
    double getVirusDensity() const;
    int getHealthStatus() const;
    int getActivityStatus() const;
    int getVaccine() const;
    void setVirusDensity(double value);
    void setHealthStatus(int value);
    void setActivityStatus(int value);
    void setVaccine(int value);
    void updateHealthStatus();//用于根据病毒密度更新健康状态，病毒类可以作为参数
    double getImmunity() const;
    void setImmunity(double value);
    void virusGrowth();//病毒自然增长，定义在feature_virus
    void treatment();//治疗，定义在feature_virus
    QPainterPath shape() const override;//碰撞范围和形状
    Resident& operator=(Resident &a);//重载=运算符
    void goDeadth();//死亡函数，设置状态和透明/空白
private:
    double virusDensity;//病毒密度
    int healthStatus;//健康状态（健康0、感染潜伏1、感染出症状2、重症3、死亡4）取决于病毒密度
    int activityStatus;//活动状态（自由活动0、密切接触1、独立隔离2、确诊3、治疗中4、治愈5）
    int vaccine;//1表示接种了疫苗，0表示没有接种疫苗
    double immunity;//免疫力0-1，adult：1，student：0.8，senior：0.6
    int infectivity;//传染人数上限3
signals:

};

#endif // RESIDENT_H
