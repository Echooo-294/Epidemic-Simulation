/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-21
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>
#include<mainwindow.h>

//疫苗接种+戴口罩+适度管控
void MapQGraphics::policy3()
{
    policy=3;
    v.setMaskEffect(0.7);//口罩影响
    v.setSocialEffect(0.5);//适度管控
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation3);//每500ms全部人要做的
//    timer2=new QTimer(this);
//    connect(timer2,&QTimer::timeout,this,&MapQGraphics::everyday);//每24h更新统计结果
    timer1->start(interval);//代表2小时
//    timer2->start(interval*12);//代表24小时
    //设置结束条件
    if(deadNumber>=initPopulation)
    {
        timer1->stop();
        return;
    }
}

//每2小时全部人要做的
void MapQGraphics::simulation3()
{
    updateShowTime();//时间更新
    //不同时间段活动
    if(showTime==6.0)//仅上下班，不去堂食
        path(1);
    else if(showTime==20.0)
        path(4);
    else if(showTime==0.0)
        everyday();
    else
    {
        int i=0;
        int activityStatus=0;
        int healthStatus=0;
        for(;i<initPopulation;i++)//遍历整个人群，注意死亡如何处理
        {
            people[i].updateHealthStatus();//更新自身状态
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态
            //完全开放唯一的措施是自行进入医院
            //如果是感染者，且本身不在隔离和治疗中，判断是否进入医院
            int restroom=buildings[5]->getRestRoom();
            if(activityStatus!=4&&activityStatus!=2&&healthStatus!=0)
            {
                if(healthStatus==3&&restroom>0)//重症直接进入医院
                    people[i].goHospital(buildings[5]);
                else if(healthStatus==2&&restroom>0)//有症状的有概率进医院
                    if(randDouble()<0.7)
                        people[i].goHospital(buildings[5]);
            }
            if(healthStatus==4||activityStatus==4)//如果死亡，则跳到下一个人
                continue;
            if(randDouble()<activityWill())//获得当前时间的活动意愿)//不移动
                randMove(i);//随机移动
            //如果是感染者且不在治疗和隔离中，则去感染别人
            if(activityStatus!=4&&activityStatus!=2&&healthStatus!=0)
                if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                    infecting1(i);
        }
    }
}




