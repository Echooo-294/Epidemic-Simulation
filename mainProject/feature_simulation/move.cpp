/*
 * @Description: 移动
 * @Author: Echooo
 * @Date: 2022-04-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-19
 */
#include"mapqgraphics.h"
#include<feature_timeAndStatistic/statistic.h>

double activityWill()//一天中不同时间段活动意愿不同
{
    double activityWill=0;
     if(showTime>0&&showTime<=6.0)//凌晨
         activityWill=0.05;
     else if(showTime>6.0&&showTime<=8.0)//早餐
         activityWill=0.3;
     else if(showTime>8.0&&showTime<=11.0)//上午
         activityWill=0.6;
     else if(showTime>11.0&&showTime<=13.0)//正午
         activityWill=0.8;
     else if(showTime>13.0&&showTime<=14.0)//午休
         activityWill=0.2;
     else if(showTime>14.0&&showTime<=18.0)//下午
         activityWill=0.6;
     else if(showTime>18.0&&showTime<=20.0)//傍晚
         activityWill=0.5;
     else if(showTime>20.0&&showTime<=22.0)//晚上
         activityWill=0.8;
     else if(showTime>22.0&&showTime<=24.0)//深夜
         activityWill=0.1;
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
    const double w=activityWill();//获得当前时间的活动意愿
    double p=randDouble();//随机数，返回的是0-1的值
    if(p>=w)//不移动
        return;
    else
        p=p/w;//移动，并且修正概率为0-1之间的值

    const int distance=10;//移动距离
    int px=people[i].x();
    int py=people[i].y();
    const int where=judgeWhere(i);
    if(where>=0)//如果在建筑中
    {
        Space *b=buildings[where];//获取所在的建筑
        const int bx=b->getPosition().x();
        const int by=b->getPosition().y();
        const int bw=b->getWidth();
        const int bl=b->getLength();

        //判断移动方向，且移动后是否出界，出了就反向走
        if(p<0.25)//右
            {
                if(px+distance<=bx+bw)
                    people[i].moveBy(distance,0);//一次移动10
                else
                    people[i].moveBy(-distance,0);
            }
            else if(p<0.5&&p>=0.25)//下
            {
                if(py+distance<=by+bl)
                    people[i].moveBy(0,distance);
                else
                    people[i].moveBy(0,-distance);
            }
            else if(p<0.75&&p>=0.5)//左
            {
                if(px-distance>=bx)
                    people[i].moveBy(-distance,0);
                else
                    people[i].moveBy(distance,0);
            }
            else//上
            {
                if(py-distance>=by)
                    people[i].moveBy(0,-distance);
                else
                    people[i].moveBy(0,distance);
            }
    }
}
