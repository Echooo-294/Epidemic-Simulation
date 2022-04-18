/*
 * @Description: 感染概率
 * @Author: Mars
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-18
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
#include"mapqgraphics.h"
/*
 * 使用前提：注意政策
 * 参数：两个居民对象（带病毒者和被计算感染概率者）和病毒对象
 * 使用时间和空间：出现感染者后，对感染者周围4米范围内每一小时计算一次
 */
bool MapQGraphics::infectionP(int i)
{
    //如果已治愈则无法感染
    //如果感染次数达到上限也返回0，不能感染
    double density=people[i].getVirusDensity();//病毒密度
    double status=0;//病毒感染者是潜伏or出症状，两者概率不同
    if(people[i].getHealthStatus()==1)
        status=v.getgrowthRate1();
    else
        status=v.getgrowthRate2();
    double vaccine=1;//是否打疫苗
    double mask=v.getmaskEffectiveness(); //是否做了防护措施 看政策 可能还要加参数
    double place=1; //所处空间的感染概率  感觉要在resident里加入判断人在什么地方的函数
    double p=density*status*vaccine*mask*place;
    //随机数判断是否感染
    double pp=randDouble();
    if(pp<p)
        return 1;
    else
        return 0;
    return 0;
}
void MapQGraphics::infecting1(int i)//感染者去感染他人
{
    QList<QGraphicsItem*>::const_iterator  iter;
    int j=0;
    QList<QGraphicsItem*> list=people[i].collidingItems();
    for(iter=list.constBegin(); iter!=list.constEnd(); iter++,j++)
    {
        if(people[i].collidingItems().isEmpty()) break;
        else
        {
            if(infectionP(i))
                list[j]->setData(1,"ganran");
        }
    }


    //对于第i个人，判断在运行的某一时刻与其发生碰撞的居民中，有无感染人员
    //如果有，就将此人状态改为感染，且颜色设置为红色
    //collidingItems返回碰撞的图元
    //qDebug()<<people[i].collidingItems()[j]->data(1).toString();
    //if(people[i].collidingItems()[0]->data(1).toString()=="ganran")
    //    qDebug()<<people[i].collidingItems()[0]->data(1).toString();
//    QList<QGraphicsItem*>::const_iterator  iter;
//    int j=0;
//    QList<QGraphicsItem*> list=people[i].collidingItems();
//    for(iter=list.constBegin(); iter!=list.constEnd(); iter++,j++)
//    {

//        if(people[i].collidingItems().isEmpty()) break;
//        if(people[i].collidingItems().at(j)->data(1).toString()=="ganran")
//        {
//            people[i].setHealthStatus(1);
//            people[i].setBrush(QBrush(Qt::red));
//            infectionNumber++;
//        }
//    }
    //        if(people[i].collidesWithItem(&people[0]))
    //        {
    //                people[i].setHealthStatus(1);
    //                people[i].setBrush(QBrush(Qt::red));
    //        }
}

