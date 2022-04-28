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
#include<feature_space/space.h>

Resident::Resident(QObject *parent, double im) : QObject(parent),virusDensity(0),healthStatus(0)\
  ,activityStatus(0),vaccine(0),immunity(im),infNumber(0),isolateDay(0)
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

bool Resident::getVaccine() const
{
    return vaccine;
}

void Resident::setActivityStatus(int value)
{
    activityStatus = value;
}

void Resident::setVaccine()
{
    vaccine = 1;
    immunity++;
}

void Resident::updateHealthStatus()
{
    const int oldHealthStatus=healthStatus;//记录旧的健康状态

    //根据密度更新健康状态，确认和密度绑定
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

    //旧状态为健康
    if(oldHealthStatus==0)
    {
        if(data(1).toString()=="infected")//由健康变感染潜伏
        {
            healthStatus=1;
            virusDensity=0.03;//初始密度
            setBrush(QBrush(Qt::red));
            infectionNumber++;//总感染+1
            healthNumber--;//正常-1
        }
    }//旧状态为感染潜伏
    else if(oldHealthStatus==1)
    {
        //变为健康的在treatment处设置
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
            infectionNumber--;//感染者-1
            seriousNumber--;//重症-1
            goDeadth();//执行死亡函数
        }
        else if(healthStatus==2)
            seriousNumber--;
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
    path.addEllipse(0,0,10,10);//设置碰撞范围
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
    qreal x=-5000;
    setPos(x,x);//移去墓地
    //setBrush(QBrush(Qt::black));//设置颜色
}

void Resident::goHospital(Space *h)
{
    //判断是否满床位，满床位则return
    if(h->getRestRoom()==0)
        return;
    activityStatus=4;//设置活动状态为治疗中4
    setPos(h->getPosition().x()+randDouble()*180,h->getPosition().y()+randDouble()*300);//设置位置
    setBrush(QBrush(Qt::blue));
    h->restRoomDec();//剩余床位-1
    isolationNumber++;
}

void Resident::goHome()
{
    double r=randDouble();
    if(r<0.25)
        setPos(100,76);
    else if(r<0.5)
        setPos(100,671);
    else if(r<0.75)
        setPos(973,76);
    else
        setPos(973,671);//随便回一栋居民楼即可，但是不要集中
    activityStatus=0;//设置活动状态为自由0
    healthStatus=0;//健康状态为健康
    setBrush(QBrush(Qt::green));
    isolationNumber--;
}

void Resident::goIsolate(Space *h)
{
    if(h->getRestRoom()==0)
        return;
    activityStatus=2;//活动状态为隔离
    setPos(1095+randDouble()*180,445+randDouble()*300);
    setBrush(QBrush(Qt::yellow));
    isolationNumber++;
    h->restRoomDec();
}

int Resident::getIsolateDay() const
{
    return isolateDay;
}

void Resident::isolateDayInc()
{
    isolateDay++;
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
