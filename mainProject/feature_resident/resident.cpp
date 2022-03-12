/*
 * @Description: 居民类的实现
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-12
 */

#include "resident.h"

Resident::Resident(QObject *parent) : QObject(parent)
{

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
    double growthRate=0.03;
    int incubationPeriod=10;
    double boundary1=incubationPeriod*growthRate;//潜伏与出症状的密度界限
    double boundary2=0.75;//非重症与重症的密度界限
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
