/*
 * @Description: 居民类的实现
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-21
 */

#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>

Resident::Resident(QObject *parent, double im) : QObject(parent),virusDensity(0),healthStatus(0)\
  ,activityStatus(0),vaccine(0),immunity(im),infNumber(0)
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
    const int oldHealthStatus=healthStatus;//记录旧的健康状态
//    const int oldActivityStatus=activityStatus;//记录旧的活动状态

    //确认状态和密度绑定，并根据密度更新健康状态
    double boundary1=v.getBoundary1();//潜伏与出症状的密度界限
    double boundary2=v.getBoundary2();//非重症与重症的密度界限
    if(virusDensity==0)
        healthStatus=0;//健康
    else if(virusDensity>0&&virusDensity<boundary1)
        healthStatus=1;//感染潜伏
    else if(virusDensity>=boundary1&&virusDensity<boundary2)
        healthStatus=2;//感染出症状
    else if(virusDensity>=boundary2&&virusDensity<1)
        healthStatus=3;//重症
    else if(virusDensity>=1)
        healthStatus=4;//死亡

    //根据位置更新活动状态？

    //旧状态为健康
    if(oldHealthStatus==0)
    {
        if(data(1).toString()=="infected")//由健康变感染潜伏
        {
            healthStatus=1;
            virusDensity=0.03;//初始密度
            setBrush(QBrush(Qt::red));
            infectionNumber++;//总感染+1
            nosymNumber++;//无症状+1
            healthNumber--;//正常-1
        }
    }//旧状态为感染潜伏
    else if(oldHealthStatus==1)
    {
        if(healthStatus==2)//变为出症状
            nosymNumber--;//无症状-1
    }//旧状态为出症状
    else if(oldHealthStatus==2)
    {
        if(healthStatus==3)//变为重症
            seriousNumber++;//重症+1
    }//旧状态为重症
    else if(oldHealthStatus==3)
    {
        if(healthStatus==4)//死亡
        {
            deadNumber++;//死亡+1
            //goDeadth();//执行死亡函数
        }
    }
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
    path.addEllipse(0,0,20,20);//设置碰撞范围
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
    //设置透明or空白，修改相关统计结果
}

void Resident::setVirusDensity(double value)
{
    virusDensity = value;
}

void Resident::setHealthStatus(int value)
{
    healthStatus = value;
}

void Resident::infNumInc()
{
    infNumber++;
}

int Resident::getInfNumber() const
{
    return infNumber;
}
