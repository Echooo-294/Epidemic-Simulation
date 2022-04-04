/*
 * @Description: 初始化
 * @Author: Echooo
 * @Date: 2022-03-26
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-04
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>


//初始化全部人群
void MapQGraphics::initPeople()
{
    allPeople.reserve(population);
    for(int i=0;i<population;i++)
    {
        Resident* adult;
        allPeople.append(adult);
    }
}
//初始化潜伏感染者
void MapQGraphics::initIncubation()
{
    incubations.reserve(initInfection);
    QVector<Resident*>::iterator iter=allPeople.begin();
    for(int i=0;i<initInfection;i++)//初始感染潜伏
    {
        (*iter)->setHealthStatus(1);//全体人群从0开始感染
        incubations.append(*iter);//并且添加到新感染潜伏数组
        iter++;
    }
}
