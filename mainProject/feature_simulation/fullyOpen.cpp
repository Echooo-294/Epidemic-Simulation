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
void virusGrowth(Resident* people);
void treatment(Resident* people);

void MapQGraphics::fullyOpen()
{
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation1);//每500ms全部人要做的
    timer1->start(200);
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&showStatistic);//每24h更新统计结果
    timer2->start(2400);
}
//每500ms全部人要做的(分组类并行，分三十趟，100个先移动，再感染或者其他，重复)
void MapQGraphics::simulation1()
{
    //QVector<Resident*>::iterator iterall=allPeople.begin();//全体
    //QVector<Resident*>::iterator iter1=incubations.begin();//感染潜伏
    int activityStatus=0;
    //double p=0;
    updateShowTime();//时间更新
    int i=0;
    for(i=0;i<400;i++)
    {
        randMove(i);//随机移动
        QList<QGraphicsItem*>::iterator iter=people[i].collidingItems().begin();

//      int j=0;
        //qDebug()<<people[i].collidingItems()[j]->data(1).toString();
//        if(people[i].collidingItems()[0]->data(1).toString()=="ganran")
//            qDebug()<<people[i].collidingItems()[0]->data(1).toString();
//        for(; iter<people[i].collidingItems().end(); iter++,j++)
//        {
//            if(people[i].collidingItems()[j]->data(1).toString()=="ganran")
//            {
//                    people[i].setHealthStatus(1);
//                    people[i].setBrush(QBrush(Qt::red));
//            }

//        }
        if(people[i].collidesWithItem(&people[0]))
        {
                people[i].setHealthStatus(1);
                people[i].setBrush(QBrush(Qt::red));
        }


        //people[i].updateHealthStatus();//更新自身状态
        //int healthStatus=people[i].getHealthStatus();//健康状态
        activityStatus=people[i].getActivityStatus();

//        if(healthStatus==1)
//        {
//            people[i].setBrush(QBrush(Qt::red));
//        }//感染者感染

//        if(healthStatus!=0&&healthStatus!=4)
//            virusGrowth(*iterall);//病毒密度更新
//        else
//            continue;//如果健康或死亡则下一个人
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
//        if(activityStatus==4)//治疗
//        {
//            treatment(*iterall);
//        }

    }
}




