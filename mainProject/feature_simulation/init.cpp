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
void MapQGraphics::randMove(int i)
{
    const double p=getrand();//随机数选择一个方向前进
    if(p<0.25)
    {
       people[i].moveBy(10,0);//判断移动后是否出界 如果不出就走 出了就反向走
    }
    else if(p<0.5&&p>=0.25)
    {
       people[i].moveBy(0,10);
    }
    else if(p<0.75&&p>=0.5)
    {
        people[i].moveBy(-10,0);
    }
    else
    {
        people[i].moveBy(0,-10);
    }
}