/*
 * @Description: 居民类的声明
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-21
 */

#ifndef RESIDENT_H
#define RESIDENT_H

#include <QObject>
#include <QPoint>
#include <QTime>
#include<feature_virus/virus.h>
#include<QGraphicsEllipseItem>
#include<QBrush>
#include<feature_space/space.h>

class Resident : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit Resident(QObject *parent = nullptr,double im=1.0);
    double getVirusDensity() const;
    int getHealthStatus() const;
    int getActivityStatus() const;
    bool getVaccine() const;
    double getImmunity() const;
    int getInfNumber() const;

    void setVirusDensity(double value);
    void setHealthStatus(int value);
    void setActivityStatus(int value);
    void setVaccine(bool value);
    void setImmunity(double value);
    void infNumInc();//传染人数+1

    void updateHealthStatus();//用于更新状态
    void virusGrowth();//病毒自然增长，定义在feature_virus
    void treatment(int &restroom);//治疗，定义在feature_virus
    QPainterPath shape() const override;//碰撞范围和形状
    Resident& operator=(Resident &a);//重载=运算符
    void goDeadth();//死亡函数，设置去墓地
    void goHospital(int &restroom);//去医院
    void goHome();//从隔离区、医院回家

private:
    double virusDensity;//病毒密度
    int healthStatus;//健康状态（健康0、感染潜伏1、感染出症状2、重症3、死亡4）取决于病毒密度
    int activityStatus;//活动状态（自由活动0、密切接触1、独立隔离2、确诊3、治疗中4）
    bool vaccine;//1表示接种了疫苗，0表示没有接种疫苗，感染概率因子为0.4，重症因子为0.2
    double immunity;
    //免疫力0-1，adult：1，student：0.8，senior：0.6，和感染概率、治疗速度、治疗有效率相关
    int infNumber;//作为感染者时的传染人数，有传染人数上限R0
signals:

};

#endif // RESIDENT_H
