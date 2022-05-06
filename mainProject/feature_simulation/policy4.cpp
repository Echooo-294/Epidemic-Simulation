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

//疫苗接种+戴口罩+严格管控+零容忍
void MapQGraphics::policy4()
{
    policy=4;
    //政策影响
    v.setHealthEffect(0.5);//卫生政策
    v.setSocialEffect(0.4);//严格社交管控
    //设置医院和隔离区容量
    buildings[5]->setRestRoom(initPopulation*0.25);
    buildings[6]->setRestRoom(initPopulation*0.4);

    //每interval ms全部人要做的
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation4);
    timer1->start(interval);//代表2小时

}

//每2小时全部人要做的
void MapQGraphics::simulation4()
{
    //不同时间段活动
    if(day%7!=0&&showTime==6.0)
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

//            if(activityStatus<=1&&people[i].data(2).toString()=="mijie")
//            {
//                    people[i].goIsolate(buildings[6]);
//                    people[i].setData(2,"geli");
//            }
            //密接者隔离，居家隔离的也会被独立隔离
            if(activityStatus!=2&&activityStatus!=4)
            {
                if(people[i].data(2).toString()=="mijie"||people[i].getVirusDensity()>0.03)
                {
                    people[i].goIsolate(buildings[6]);
                    people[i].setData(2,"geli");
                }
            }

            //如果是感染者，且本身不在治疗中，判断是否进入医院
            int restroom=buildings[5]->getRestRoom();
            if(activityStatus!=4&&healthStatus!=0)
            {
                if(healthStatus==3&&restroom>0)//重症进入医院
                {
                    if(judgeWhere(i)!=6)
                        isolationNumber++;
                    people[i].goHospital(buildings[5]);
                }
                else if(healthStatus>=1&&restroom>0)//感染者有概率进医院
                {
                    if(healthStatus==2&&randDouble()<0.8)
                    {
                        if(judgeWhere(i)!=6)
                            isolationNumber++;
                        people[i].goHospital(buildings[5]);
                    }
                    else if(healthStatus==1&&activityStatus==2&&randDouble()<0.6)
                    {
                        if(judgeWhere(i)!=6)
                            isolationNumber++;
                        people[i].goHospital(buildings[5]);
                    }
                }
            }
            if(activityStatus==2||activityStatus==4)//如果被隔离则跳过
                continue;
            if(randDouble()<activityWill())//获得当前时间的活动意愿)//不移动
                randMove(i);//随机移动
            //如果是感染者且不在治疗和隔离中，则去感染别人
            if(activityStatus<=1&&healthStatus!=0)
                if(people[i].getInfNumber()<v.getR0())//如果感染者感染人数未超限，则去感染他人
                    infecting3(i);
        }
    }
    updateShowTime();//时间更新
}




