/*
 * @Description: 初始化、随机移动
 * @Author: Echooo
 * @Date: 2022-03-26
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-10
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>

//初始化全部人群
void MapQGraphics::initPeople()
{//allpeople是定义在mapQGraphics中的总人群容器，initPopulation是定义在statistic中的初始总人数
    allPeople.reserve(initPopulation);
    for(int i=0;i<initPopulation;i++)
    {//初始化居民
        Resident* adult;
        allPeople.append(adult);
    }
}
//初始化潜伏感染者
void MapQGraphics::initIncubation()
{//incubations是定义在mapQGraphics中的总感染潜伏容器，initInfection是定义在statistic中的初始感染人数
    incubations.reserve(initInfection);
    QVector<Resident*>::iterator iter=allPeople.begin();
    for(int i=0;i<initInfection;i++)//初始的感染者全部是感染潜伏
    {
        //people[i].setHealthStatus(1);//全体人群从0开始感染
        incubations.append(*iter);//并且添加到新感染潜伏数组
        iter++;
    }
}


