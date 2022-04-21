/*
 * @Description: 感染
 * @Author: Mars
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-19
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
#include"mapqgraphics.h"

bool MapQGraphics::judgeInfected(int i)
{
    //如果已治愈则无法感染
    //如果感染次数达到上限也返回0，不能感染
    double status=0;//病毒感染者是潜伏or出症状，两者概率不同
    if(people[i].getVirusDensity()<v.getBoundary1())
        status=v.getInfectionP1();
    else
        status=v.getgrowthRate2();
    double vaccine=1;//疫苗影响
    double mask=v.getmaskEffect(); //是否做了防护措施 看政策 可能还要加参数
    double place=0.9; //所处空间的感染概率，公共、居民楼、写字楼、医院、隔离
    double P=status*vaccine*mask*place;
    //随机数判断是否感染
    double pp=randDouble();
    if(pp<P)
        return 1;
    else
        return 0;
    return 0;
}
void MapQGraphics::infecting1(int i)//感染者去感染他人，先将被感染者设置data，延后状态和颜色更新
{
    QList<QGraphicsItem*> list=people[i].collidingItems();//返回碰撞图元QList
    if(list.isEmpty())
        return;//如果没有碰撞到其他人，则返回
    const int size=list.size();
    int j=0;
    int number=0;//用来记录该感染者感染了多少人
    for(;j<size;j++)
    {
        if(list[j]->data(1).toString()!="infected")//如果未被感染
            if(judgeInfected(i))//随机判断是否被感染了
            {
                list[j]->setData(1,"infected");//如果被感染则设置一个data标志，延后至更新状态时感染
                number++;
            }
        if(number>=3)//超过感染上限
            return;
    }
}

