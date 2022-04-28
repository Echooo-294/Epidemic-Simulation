/*
 * @Description: 移动
 * @Author: Echooo
 * @Date: 2022-04-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-21
 */
#include"mapqgraphics.h"
#include<mainwindow.h>
#include<feature_timeAndStatistic/statistic.h>
#include <QGraphicsItemAnimation>

#include<QTimeLine>

double activityWill()//一天中不同时间段活动意愿不同
{
    double activityWill=0;
     if(showTime>0&&showTime<=6.0)//凌晨
         activityWill=0.1;
     else if(showTime>6.0&&showTime<=8.0)//早晨
         activityWill=0.5;
     else if(showTime>8.0&&showTime<=11.0)//上午
         activityWill=0.7;
     else if(showTime>11.0&&showTime<=13.0)//正午
         activityWill=0.9;
     else if(showTime>13.0&&showTime<=14.0)//午休
         activityWill=0.4;
     else if(showTime>14.0&&showTime<=18.0)//下午
         activityWill=0.8;
     else if(showTime>18.0&&showTime<=20.0)//傍晚
         activityWill=0.6;
     else if(showTime>20.0&&showTime<=22.0)//晚上
         activityWill=0.8;
     else if(showTime>22.0&&showTime<=24.0)//深夜
         activityWill=0.2;
     return activityWill;
}
int MapQGraphics::judgeWhere(int i)//判断居民i是否位于某个建筑中，如果是，就返回该建筑标号
{
    //可以根据模拟活动简化判断
    //获取人的位置
    int px=people[i].x();
    int py=people[i].y();
    //存放建筑j的x,y,长，宽
    int bx=0;
    int by=0;
    int bw=0;
    int bl=0;
    //用于判断是否在建筑内
    bool flag=0;
    int j=0;
    for(;j<buildingNumber;j++)
    {
        //传建筑位置参数
        bx=buildings[j]->getPosition().x();
        by=buildings[j]->getPosition().y();
        bw=buildings[j]->getWidth();
        bl=buildings[j]->getLength();
        //判断是不是在第j个建筑中
        if(px>=bx&&px<=bx+bw&&py>=by&&py<=by+bl)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return j;
    else
        return -1;
}
void MapQGraphics::randMove(int i)
{
    const int where=judgeWhere(i);
    if(where==5||where==6)
        return;
    const double w=activityWill();//获得当前时间的活动意愿
    double p=randDouble();//随机数，返回的是0-1的值
    if(p>=w)//不移动
        return;
    else
        p=p/w;//移动，并且修正概率为0-1之间的值

    const int distance=15;//移动距离
    int px=people[i].x();
    int py=people[i].y();

    if(where>=0)//如果在建筑中
    {
        Space *b=buildings[where];//获取所在的建筑
        const int bx=b->getPosition().x();
        const int by=b->getPosition().y();
        const int bw=b->getWidth();
        const int bl=b->getLength();

        //判断移动方向，且移动后是否出界，出了就反向走
        int time=interval*0.25;//设置移动动画时间
        if(p<0.25)//右
            {
                if(px+distance<=bx+bw)
                    //people[i].moveBy(distance,0);//一次移动10
                    moveSilky(i,people[i].pos().toPoint()+QPoint(distance,0),time);
                else
                    //people[i].moveBy(-distance,0);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(-distance,0),time);
            }
            else if(p<0.5&&p>=0.25)//下
            {
                if(py+distance<=by+bl)
                    //people[i].moveBy(0,distance);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(0,distance),time);
                else
                    //people[i].moveBy(0,-distance);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(0,-distance),time);
            }
            else if(p<0.75&&p>=0.5)//左
            {
                if(px-distance>=bx)
                    //people[i].moveBy(-distance,0);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(-distance,0),time);
                else
                    //people[i].moveBy(distance,0);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(distance,0),time);
            }
            else//上
            {
                if(py-distance>=by)
                    //people[i].moveBy(0,-distance);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(0,-distance),time);
                else
                    //people[i].moveBy(0,distance);
                    moveSilky(i,people[i].pos().toPoint()+QPoint(0,distance),time);
            }
    }
}

//封装动画移动函数  参数1--people数组号；参数2--目的地；参数3--动画持续时间
void MapQGraphics::moveSilky(int i, QPoint des,int t)
{
    //获得人当前坐标
    QPoint sta=people[i].pos().toPoint();
    int dx=des.x()-sta.x();
    int dy=des.y()-sta.y();
    //---------------------实现动画效果-------------------------//
    //设置时间轴，动画时长为t ms
    QTimeLine *tline=new QTimeLine(t);
    tline->setFrameRange(0,100);
    //设置动画对象
    anima=new QGraphicsItemAnimation;//初始化
    //设置运行轨迹，共200步
    for(int j=0;j<200;j++)
        anima->setPosAt(j / 200.0
                        ,QPointF(sta.x()+dx*j/200,sta.y()+dy*j/200));
    anima->setItem(&people[i]);//设置对象
    anima->setTimeLine(tline);//设置时间轴
    //动画开始
    tline->start();
}

void MapQGraphics::path(int c)//c--活动参数--1：上班；2：去食堂；3：继续上班；4：下班
{
    int time=interval*0.75;
    switch (c)
    {
        case 1://上班
        {
            for (int i=0;i<initPopulation;i++)
            {
                if(people[i].getHealthStatus()!=4&&people[i].getActivityStatus()!=4&&people[i].getActivityStatus()!=2)
                {
                    int p=rand()%4;//获取进入写字楼的随机数
                    //获得建筑内的随机某点坐标
                    QPoint end;
                    if(p==0)
                       end=QPoint(buildings[4]->getPosition().x()+rand()% (int)buildings[4]->getWidth(),buildings[4]->getPosition().y()+rand()%(int) buildings[4]->getLength());
                    else if(p==1)
                       end=QPoint(buildings[7]->getPosition().x()+rand()% (int)buildings[7]->getWidth(),buildings[7]->getPosition().y()+rand()%(int) buildings[7]->getLength());
                    else if(p==2)
                       end=QPoint(buildings[8]->getPosition().x()+rand()% (int)buildings[8]->getWidth(),buildings[8]->getPosition().y()+rand()%(int) buildings[8]->getLength());
                    else
                       end=QPoint(buildings[9]->getPosition().x()+rand()% (int)buildings[9]->getWidth(),buildings[9]->getPosition().y()+rand()%(int) buildings[9]->getLength());
                    moveSilky(i, end,time);
                }
            }
            break;
        }
        case 2://去食堂
        {
            for (int i=0;i<initPopulation;i++)
            {
                if(people[i].getHealthStatus()!=4&&people[i].getActivityStatus()!=4&&people[i].getActivityStatus()!=2)
                {
                    int p=rand()%2;//获取进入食堂的随机数
                    //获得建筑内的随机某点坐标
                    QPoint end;
                    if(p==0)
                        end=QPoint(buildings[10]->getPosition().x()+rand()% (int)buildings[10]->getWidth(),buildings[10]->getPosition().y()+rand()%(int) buildings[10]->getLength());
                    else
                        end=QPoint(buildings[11]->getPosition().x()+rand()% (int)buildings[11]->getWidth(),buildings[11]->getPosition().y()+rand()%(int) buildings[11]->getLength());
                    moveSilky(i, end,time);
                }
            }
            break;
        }
        case 3://继续上班
        {
            for (int i=0;i<initPopulation;i++)
            {
                if(people[i].getHealthStatus()!=4&&people[i].getActivityStatus()!=4&&people[i].getActivityStatus()!=2)
                {
                    //获得建筑内的某点坐标
                    QPoint end;
                    //居民数组中0-99设置终点为1号居民楼，即buildings[0],以此类推
                    if(i<initPopulation*0.25) end=QPoint(buildings[4]->getPosition().x()+rand()% (int)buildings[4]->getWidth(),buildings[4]->getPosition().y()+rand()%(int) buildings[4]->getLength());
                    else if(i<initPopulation*0.5)  end=QPoint(buildings[7]->getPosition().x()+rand()% (int)buildings[7]->getWidth(),buildings[7]->getPosition().y()+rand()%(int) buildings[7]->getLength());
                    else if(i<initPopulation*0.75) end=QPoint(buildings[8]->getPosition().x()+rand()% (int)buildings[8]->getWidth(),buildings[8]->getPosition().y()+rand()%(int) buildings[8]->getLength());
                    else  end=QPoint(buildings[9]->getPosition().x()+rand()% (int)buildings[9]->getWidth(),buildings[9]->getPosition().y()+rand()%(int) buildings[9]->getLength());
                    moveSilky(i,end,time);
                }
            }
            break;
        }
        case 4://下班
        {
            for (int i=0;i<initPopulation;i++)
            {
                if(people[i].getHealthStatus()!=4&&people[i].getActivityStatus()!=4&&people[i].getActivityStatus()!=2)
                {
                    //获得建筑内的某点坐标
                    QPoint end;
                    //居民数组中0-99设置终点为1号居民楼，即buildings[0],以此类推
                    if(i<initPopulation*0.25) end=QPoint(buildings[0]->getPosition().x()+rand()% (int)buildings[0]->getWidth(),buildings[0]->getPosition().y()+rand()%(int) buildings[0]->getLength());
                    else if(i<initPopulation*0.5)  end=QPoint(buildings[1]->getPosition().x()+rand()% (int)buildings[1]->getWidth(),buildings[1]->getPosition().y()+rand()%(int) buildings[1]->getLength());
                    else if(i<initPopulation*0.75) end=QPoint(buildings[2]->getPosition().x()+rand()% (int)buildings[2]->getWidth(),buildings[2]->getPosition().y()+rand()%(int) buildings[2]->getLength());
                    else  end=QPoint(buildings[3]->getPosition().x()+rand()% (int)buildings[3]->getWidth(),buildings[3]->getPosition().y()+rand()%(int) buildings[3]->getLength());
                    moveSilky(i,end,time);
                }
            }
            break;
        }
}
}
