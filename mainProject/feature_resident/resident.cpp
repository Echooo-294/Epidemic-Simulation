/*
 * @Description: 居民类的实现
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-18
 */

#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>

Resident::Resident(QObject *parent, double im) : QObject(parent),virusDensity(0),healthStatus(0)\
  ,activityStatus(0),vaccine(0),immunity(im),infectivity(3)
{
    //创建时可以选择三种对象：adult,student,senior，仅免疫力不同，其他全部默认
}

double Resident::getVirusDensity() const
{
    return virusDensity;
}

int Resident::getHealthStatus() const
{
    return healthStatus;
}

int Resident::getActivityStatus() const
{
    return activityStatus;
}

int Resident::getVaccine() const
{
    return vaccine;
}

void Resident::setVirusDensity(double value)
{
    virusDensity = value;
}

void Resident::setHealthStatus(int value)
{
    healthStatus = value;
}

void Resident::setActivityStatus(int value)
{
    activityStatus = value;
}

void Resident::setVaccine(int value)
{
    vaccine = value;
}

void Resident::updateHealthStatus()
{
    double boundary1=v.getBoundary1();//潜伏与出症状的密度界限
    double boundary2=v.getBoundary2();//非重症与重症的密度界限
    if(virusDensity==0)
        setHealthStatus(0);//健康
    else if(virusDensity>0&&virusDensity<boundary1)
        setHealthStatus(1);//感染潜伏
    else if(virusDensity>=boundary1&&virusDensity<boundary2)
        setHealthStatus(2);//感染出症状
    else if(virusDensity>=boundary2&&virusDensity<1)
        setHealthStatus(3);//重症
    else if(virusDensity==1)
        setHealthStatus(4);//死亡
}

double Resident::getImmunity() const
{
    return immunity;
}

void Resident::setImmunity(double value)
{
    immunity = value;
}

QPainterPath Resident::shape() const//返回被碰撞的形状
{
    QPainterPath path;
    path.addEllipse(-20,-20,40,40);//设置碰撞范围
    return path;
}

Resident& Resident::operator=(Resident &a)
{
    virusDensity=a.getVirusDensity();
    healthStatus=a.getHealthStatus();
    activityStatus=a.getActivityStatus();
    vaccine=a.getVaccine();
    immunity=a.getImmunity();
    return *this;
}

void Resident::goDeadth()
{
    healthStatus=4;//健康状态设为死亡

}
