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

//疫苗接种+戴口罩+严格管控
void MapQGraphics::policy4()
{
    policy=4;
    v.setMaskEffect(0.6);//口罩影响
    v.setSocialEffect(0.2);//严格管控
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation4);//每500ms全部人要做的
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
void MapQGraphics::simulation4()
{
    updateShowTime();//时间更新
    //不同时间段活动
    if(showTime==6.0)
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
            //是否隔离
            if(people[i].data(2).toString()=="mijie")//密接者隔离
            {
                people[i].goIsolate(buildings[6]);
                people[i].setData(2,"geli");
            }
            people[i].updateHealthStatus();//更新自身状态
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态
            if(healthStatus==4||activityStatus==4)//如果死亡/治疗中，则跳到下一个人
                continue;
            //如果是感染者，且本身不在隔离和治疗中，判断是否进入医院
            int restroom=buildings[5]->getRestRoom();
            if(activityStatus!=4&&healthStatus!=0)
            {
                if(healthStatus==3&&restroom>0)//重症进入医院
                    people[i].goHospital(buildings[5]);
                else if(people[i].getVirusDensity()>0.1&&restroom>0)//无症状的有概率进医院(核酸检测,病毒密度大于0.05才有可能检测出来)
                    if(randDouble()<0.8)
                        people[i].goHospital(buildings[5]);
            }
            if(activityStatus==2)//如果被隔离则跳过
                continue;
            if(randDouble()<activityWill())//获得当前时间的活动意愿)//不移动
                randMove(i);//随机移动
            //如果是感染者且不在治疗和隔离中，则去感染别人
            if(activityStatus<=1&&healthStatus!=0)
                if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                    infecting3(i);
        }
    }
}




