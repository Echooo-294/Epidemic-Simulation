/*
 * @Description: 初始化
 * @Author: Echooo
 * @Date: 2022-03-26
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-26
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>

//初始参数
int population=3000;//初始总人数
int initInfection=1;//初始感染人数
double startTime=6.0;//起始时间
double updateTime=0.5;//更新间隔时间
int policy=0;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
int day=0;//天数
double time=startTime;//时间
Virus v(3,0.6,0.9,4,0.03,0.05,0.9,0.8,0.3,0.75);

//需要一个父控件，使Resident*继承他以便图形化
//需要限制初始位置
//初始化全部人群
QVector<Resident*> initPeople()
{
    QVector<Resident*> allPeople;
    allPeople.reserve(population);
    for(int i=0;i<population;i++)
    {
        Resident* adult;
        allPeople.append(adult);
    }
    return allPeople;
}
//初始化潜伏感染者，并设置新数组
QVector<Resident*> initIncubation(QVector<Resident*>& allPeople)
{
    QVector<Resident*> incubations;//感染潜伏
    incubations.reserve(initInfection);
    QVector<Resident*>::iterator iter=allPeople.begin();
    for(int i=0;i<initInfection;i++)//初始感染潜伏
    {
        (*iter)->setHealthStatus(1);
        incubations.append(*iter);
        iter++;
    }
    return incubations;
}
