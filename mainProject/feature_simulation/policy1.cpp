/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-27
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>
#include<mainwindow.h>

//只有进入医院一个特殊步骤
void MapQGraphics::policy1()
{
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation1);//每500ms全部人要做的
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&MapQGraphics::everyday);//每24h更新统计结果
    timer1->start(interval);//代表2小时
    timer2->start(interval*12);//代表24小时
}

//每2小时全部人要做的
void MapQGraphics::simulation1()
{
    if(deadNumber>=initPopulation)
    {
        timer1->stop();
        timer2->stop();
        everyday();//最后展示一遍
        qDebug()<<"全部死亡";
        return;
    }
    updateShowTime();//时间更新
    //不同时间段活动，分为上下班时间在路径移动，和其他时间随机移动
    if(showTime==6.0)//上下班不需要QTimer，只需要根据showtime判断
        path(1);
    else if(showTime==10.0)
        path(2);
    else if(showTime==14.0)
        path(3);
    else if(showTime==20.0)
        path(4);
    else
    {
        int i=0;
        int activityStatus=0;
        int healthStatus=0;
        double p=0;//用于判断是否进入医院的随机数
        for(;i<initPopulation;i++)//遍历整个人群，注意死亡如何处理
        {
            people[i].updateHealthStatus();//更新自身状态
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态
            if(healthStatus==4||activityStatus==4)//如果死亡，则跳到下一个人
                continue;
            //完全开放唯一的措施是自行进入医院
            //如果是感染者，且本身不在隔离和治疗中，判断是否进入医院
            int restroom=buildings[5]->getRestRoom();
            if(activityStatus!=4&&activityStatus!=2&&healthStatus!=0)
            {
                if(healthStatus==3&&restroom>0)//重症直接进入医院
                    people[i].goHospital(buildings[5]);
                else if(healthStatus==2&&restroom>0)//出症状的有概率进医院
                {
                    p=randDouble();
                    if(p<=0.4)
                        people[i].goHospital(buildings[5]);
                }
            }
            randMove(i);//随机移动
            //如果是感染者且不在治疗，则去感染别人
            if(activityStatus!=4&&healthStatus!=0)
                if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                    infecting1(i);
        }
    }
}




