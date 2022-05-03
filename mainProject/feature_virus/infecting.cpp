/*
 * @Description: 感染
 * @Author: Mars
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-27
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
#include"mapqgraphics.h"

bool MapQGraphics::judgeInfected(int i,int j)//i为感染者，j为健康人
{
    if(people[i].getInfNumber()>=v.getR0())
        return 0;//如果传染人数超限则返回
    double P=0;
    if(people[i].getVirusDensity()<v.getBoundary1())//病毒感染者是潜伏or出症状，两者概率不同
        P=v.getInfectionP1();
    else
        P=v.getInfectionP2();
    double vaccine=1;
    if(people[j].getVaccine())//如果接种了疫苗
        vaccine=0.4;
    const double maskEffect=v.getMaskEffect();//政策——戴口罩、消毒
    //社交管控
    const double socialEffect=v.getSocialEffect();
    //和免疫力相关
    const double immunityP=3/(4*people[j].getImmunity());

    P=P*vaccine*maskEffect*socialEffect*immunityP;
    //随机数判断是否感染
    if(randDouble()<P)
    {
        people[i].infNumInc();//该感染者的传染人数+1
        return 1;
    }
    else
        return 0;
}
void MapQGraphics::infecting1(int i)
{
    //调用前判断：感染者且不在治疗和隔离中
    //感染者去感染他人，先将被感染者设置data，延后状态和颜色更新
    QList<QGraphicsItem*> list=people[i].collidingItems();//返回碰撞图元QList
    if(list.isEmpty())
        return;//如果没有碰撞到其他人，则返回
    const int size=list.size();
    int j=0;
    for(;j<size;j++)
    {
        if(people[i].getInfNumber()>=v.getR0())//如果感染者传染人数超限，则退出
            return;
        if(list[j]->data(1).toString()!="infected")//如果未被感染
            if(judgeInfected(i,list[j]->data(3).toInt()))//随机判断是否被感染了，i是感染者，j是健康人
                list[j]->setData(1,"infected");//如果被感染则设置一个data标志，延后至更新状态时感染
    }
}
/*
void MapQGraphics::infecting2(int i)
{
    //调用前判断：健康人
    //健康人去被感染，被感染到先设置data，延后状态和颜色更新
    QList<QGraphicsItem*> list=people[i].collidingItems();//返回碰撞图元QList
    if(list.isEmpty())
        return;//如果没有碰撞到其他人，则返回
    const int size =list.size();
    int j=0;
    for(;j<size;j++)
    {
        if(list[j]->data(1).toString()=="infected")//如果碰撞到感染者
            if(judgeInfected(list[j]->data(2).toInt(),i))//随机判断是否被感染了，i是健康人，j是感染者
            {
                list[i]->setData(1,"infected");

            }
    }
}
*/
void MapQGraphics::infecting3(int i)//从感染者出发去搜查密切接触者
{
    QList<QGraphicsItem*> list=people[i].collidingItems();//返回碰撞图元QList
    if(list.isEmpty())
        return;//如果没有碰撞到其他人，则返回
    const int size=list.size();
    int j=0;
    for(;j<size;j++)
    {
        //if(people[i].getVirusDensity()>0.05)
        list[j]->setData(2,"mijie");
        if(people[i].getInfNumber()>=v.getR0())//如果感染者传染人数超限，则退出
            return;
        if(list[j]->data(1).toString()!="infected")//如果未被感染
            if(judgeInfected(i,list[j]->data(3).toInt()))//随机判断是否被感染了，i是感染者，j是健康人
                list[j]->setData(1,"infected");//如果被感染则设置一个data标志，延后至更新状态时感染
    }
}





