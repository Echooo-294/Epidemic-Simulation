/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-18
 */
#include<feature_resident/resident.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>
#include<QTimeLine>
#include<mainwindow.h>
//只有进入医院一个特殊步骤
void MapQGraphics::fullyOpen()
{
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MapQGraphics::simulation1);//每500ms全部人要做的
    timer1->start(200);//代表2小时
    timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,this,&MapQGraphics::everyday);//每24h更新统计结果
    timer2->start(2400);//代表24小时

}
void MapQGraphics::path()
{//上班
    if(showTime<=12)
    {
        for (int i=0;i<initPopulation;i++) {
            //获得人当前坐标
            QPoint sta=people[i].pos().toPoint();
            //获得建筑内的某点坐标
            QPoint end=QPoint(buildings[4]->getPosition().x()+rand()% (int)buildings[4]->getWidth(),buildings[4]->getPosition().y()+rand()%(int) buildings[4]->getLength());
            int dx=end.x()-sta.x();
            int dy=end.y()-sta.y();

            QTimeLine *tline=new QTimeLine(500);
//            tline->setCurveShape(QTimeLine::LinearCurve);
//            tline->setLoopCount(1);
            tline->setFrameRange(0,100);

            QGraphicsItemAnimation *anima=new QGraphicsItemAnimation;
            for(int j=0;j<200;j++)
                anima->setPosAt(j / 200.0
                                ,QPointF(sta.x()+dx*j/200,sta.y()+dy*j/200));
            anima->setItem(&people[i]);
            anima->setTimeLine(tline);

            tline->start();
        }
    }
//下班
    else
    {
        for (int i=0;i<initPopulation;i++) {
            //获得人当前坐标
            QPoint sta=people[i].pos().toPoint();
            //获得建筑内的某点坐标
            QPoint end;
            if(i<100) end=QPoint(buildings[0]->getPosition().x()+rand()% (int)buildings[0]->getWidth(),buildings[0]->getPosition().y()+rand()%(int) buildings[0]->getLength());
            else if(i<200)  end=QPoint(buildings[1]->getPosition().x()+rand()% (int)buildings[1]->getWidth(),buildings[1]->getPosition().y()+rand()%(int) buildings[1]->getLength());
            else if(i<300) end=QPoint(buildings[2]->getPosition().x()+rand()% (int)buildings[2]->getWidth(),buildings[2]->getPosition().y()+rand()%(int) buildings[2]->getLength());
            else  end=QPoint(buildings[3]->getPosition().x()+rand()% (int)buildings[3]->getWidth(),buildings[3]->getPosition().y()+rand()%(int) buildings[3]->getLength());
            int dx=end.x()-sta.x();
            int dy=end.y()-sta.y();

            QTimeLine *tline=new QTimeLine(500);
//            tline->setCurveShape(QTimeLine::LinearCurve);
//            tline->setLoopCount(1);
            tline->setFrameRange(0,100);

            QGraphicsItemAnimation *anima=new QGraphicsItemAnimation;
            for(int j=0;j<200;j++)
                anima->setPosAt(j / 200.0
                                ,QPointF(sta.x()+dx*j/200,sta.y()+dy*j/200));
            anima->setItem(&people[i]);
            anima->setTimeLine(tline);

            tline->start();
        }
    }
}

//每2小时全部人要做的(分组类并行，分三十趟，100个先移动，再感染或者其他，重复)
void MapQGraphics::simulation1()
{
    updateShowTime();//时间更新
    int activityStatus=0;
    int healthStatus=0;
    //double p=0;
    //不同时间段活动
    //分为上下班时间在路径移动，和其他时间自由移动
    if(showTime==6||showTime==20)
    {
        path();
    }
    else
    {
        //选择感染方式：如果感染者多，让健康者被感染；如果健康者多，让感染者去感染别人
        //先在循环外判断，不考虑操作过程中的人数变化
        //可以预估可能被感染的人数（考虑人数变化），再抉择方案
        int i=0;
        int flag=0;
        if(healthNumber<infectionNumber-isolationNumber)
            flag=1;
        for(;i<initPopulation;i++)//遍历整个人群，注意死亡如何处理
        {
            randMove(i);//随机移动
            people[i].updateHealthStatus();//更新自身状态
            healthStatus=people[i].getHealthStatus();//健康状态
            activityStatus=people[i].getActivityStatus();//活动状态
            if(flag==0)//健康人多，让感染者去感染他人（不用考虑健康人）
            {
    //            if(healthStatus==0&&healthStatus==4)//如果健康或死亡则下一个人，其他模拟还要考虑活动状态
    //                continue;
                //如果是感染者且不在治疗中（完全开放没有其他措施），则去感染别人
                if(activityStatus!=4&&healthStatus!=0&&healthStatus!=4)
                {
                    infecting1(i);
                }
            }
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




