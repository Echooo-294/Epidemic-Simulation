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

//只有进入医院一个特殊步骤
void MapQGraphics::fullyOpen()
{
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation1);//每500ms全部人要做的
    timer1->start(interval);//代表2小时
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&MapQGraphics::everyday);//每24h更新统计结果
    timer2->start(interval*12);//代表24小时
}

//每2小时全部人要做的(分组类并行，分三十趟，100个先移动，再感染或者其他，重复)
void MapQGraphics::simulation1()
{
    if(deadNumber>=initPopulation)
    {
        qDebug()<<"全部死亡";
        timer1->stop();
        timer2->stop();
        return;
    }
    updateShowTime();//时间更新
    //不同时间段活动，分为上下班时间在路径移动，和其他时间随机移动
    if(showTime==8.0||showTime==20.0)//上下班不需要QTimer，只需要根据showtime判断
        path();
    else
    {
        //选择感染方式：如果感染者多，让健康者被感染；如果健康者多，让感染者去感染别人
        //先在循环外判断，不考虑操作过程中的人数变化
        //可以预估可能被感染的人数（考虑人数变化），再抉择方案
        int i=0;
        int activityStatus=0;
        int healthStatus=0;
        int flag=0;
//        if(healthNumber<infectionNumber-isolationNumber)
//            flag=1;
        for(;i<initPopulation;i++)//遍历整个人群，注意死亡如何处理
        {
            //死亡是否还需要继续？
            people[i].updateHealthStatus();//更新自身状态
            if(people[i].getHealthStatus()!=4)
            {
                randMove(i);//随机移动
            }
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态

            if(people[i].getHealthStatus()!=4)//没死就移动，医院和隔离是否可以移动？
                randMove(i);//随机移动
            if(flag==0)//健康人多，让感染者去感染他人（不用考虑健康人）
            {
                //如果是感染者且不在治疗和隔离中，则去感染别人
                if(activityStatus!=4&&activityStatus!=2&&healthStatus!=0&&healthStatus!=4)
                {
                    if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                        infecting1(i);
                }
            }
//            else
//            {
                             //如果已治愈可以跳过感染阶段
//            }
        }
    }

//    for(int i=0;i<initPopulation;i++)
//    {
//        healthStatus=people[i].getHealthStatus();
//        if(healthStatus==1||healthStatus==4)
//            continue;
//        if(people[i].data(1).toString()=="ganran")
//        {
//            people[i].setHealthStatus(1);
//            people[i].setBrush(QBrush(Qt::red));
//        }
//    }
    //        if(activityStatus!=4)//是否进入医院
    //        {
    //            if(healthStatus==3)
    //            {
    //                //进入医院
    //            }
    //            else
    //            {
    //                 p=getrand();
    //                 if(p>0&&p<=0.5)
    //                 {}//进入医院
    //            }
    //        }
}




