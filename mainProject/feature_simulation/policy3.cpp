/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-05-05
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>
#include<mainwindow.h>

//疫苗接种+戴口罩+适度管控
void MapQGraphics::policy3()
{
    policy=3;
    //政策影响
    v.setHealthEffect(0.6);//卫生政策
    v.setSocialEffect(0.6);//适度社交管控
    //设置医院和隔离区容量
    buildings[5]->setRestRoom(initPopulation*0.2);
    buildings[5]->setRestRoom(initPopulation*0.3);

    //每interval ms全部人要做的
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation3);
    timer1->start(interval);//代表2小时

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
    //不同时间段活动
    if(day%7!=0&&showTime==6.0)//仅上下班，不去堂食
        path(1);
    else if(day%7!=0&&showTime==20.0)
        path(4);
    else if(showTime==0.0)
        everyday();
    else
    {
        int i=0;
        int activityStatus=0;
        int healthStatus=0;
        for(;i<initPopulation;i++)//遍历整个人群
        {
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态
            if(healthStatus==4||activityStatus==4)//如果死亡/治疗中，则跳到下一个人
                continue;

            //更新自身状态
            if(healthStatus==0&&people[i].data(1).toString()=="infected")//由健康变感染潜伏
            {
                people[i].setHealthStatus(1);
                people[i].setVirusDensity(0.03);//赋予初始病毒密度
                if(activityStatus!=2&&activityStatus!=4)
                    people[i].setBrush(QBrush("#dc6b82"));
                infectionNumber++;//总感染+1
                healthNumber--;//正常-1
            }

            //如果是感染者，且本身不在治疗中，判断是否进入医院
            int restroom=buildings[5]->getRestRoom();
            if(activityStatus!=4&&healthStatus!=0)
            {
                if(healthStatus==3&&restroom>0)//重症直接进入医院
                {
                    people[i].goHospital(buildings[5]);
                    isolationNumber++;
                }
                else if(healthStatus==2&&restroom>0)//有症状的有概率进医院
                    if(randDouble()<0.7)
                    {
                        people[i].goHospital(buildings[5]);
                        isolationNumber++;
                    }
            }
            if(randDouble()<activityWill())//获得当前时间的活动意愿
                randMove(i);//随机移动
            //如果是感染者且不在治疗和隔离中，则去感染别人
            if(activityStatus<=1&&healthStatus!=0)
                if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                    infecting1(i);
        }
    }
    updateShowTime();//时间更新
}




