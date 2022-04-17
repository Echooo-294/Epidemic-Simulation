/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-12
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>
#include<mainwindow.h>

void MapQGraphics::fullyOpen()
{
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation1);//每500ms全部人要做的
    timer1->start(200);
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&MapQGraphics::everyday);//每24h更新统计结果
    timer2->start(2400);
}
//每500ms全部人要做的(分组类并行，分三十趟，100个先移动，再感染或者其他，重复)
void MapQGraphics::simulation1()
{
    int activityStatus=0;
    int healthStatus=0;
    //double p=0;
    updateShowTime();//时间更新
    int i=0;
    int flag=0;
    //选择感染方式：如果感染者多，让健康者被感染；如果健康者多，让感染者去感染别人
    //先在循环外判断，不考虑操作过程中的人数变化
    //可以预估可能被感染的人数（考虑人数变化），再抉择方案
    if(healthNumber<infectionNumber-isolationNumber)
        flag=1;
    for(i=0;i<livingNumber;i++)
    {
        people[i].updateHealthStatus();//更新自身状态
        randMove(i);//随机移动
        healthStatus=people[i].getHealthStatus();//健康状态
        activityStatus=people[i].getActivityStatus();//活动状态
        if(flag==0)//健康人多，让感染者去感染他人（不用考虑健康人）
        {
            if(healthStatus==0&&healthStatus==4)//如果健康或死亡则下一个人，其他模拟还要考虑活动状态
                continue;
            //如果是感染者且不在治疗中（完全开放没有其他措施），则去感染别人
            if(activityStatus!=4)
            {
                //infecting(i);
            }

        }
        else
        {

        }
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
}




