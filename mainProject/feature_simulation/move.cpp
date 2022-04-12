/*
 * @Description: 移动
 * @Author: Echooo
 * @Date: 2022-04-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-12
 */
#include"mapqgraphics.h"
#include<feature_timeAndStatistic/statistic.h>

QPoint movelittle(QPoint p1, QPoint p2)
{
    //获取符号
    int dX=p2.x()-p1.x()/abs(p2.x()-p1.x());
    int dY=p2.y()-p1.y()/abs(p2.y()-p1.y());

    int ratio=dY/dX;
    int x=p1.x(),y=p1.y();
    switch(randInt()%7)
    {
    case 0:{//反方向
        int r=randInt()%100;
        if(x>50) x=x-r*dX;
        if(y>50) y=y-r*ratio*dY;
            }
    case 1:{//一侧
        int r=randInt()%100;
        x=x+r*dX;
        if(y>50) y=y-r*ratio*dY;
            }
    case 2:{//另一侧
        int r=randInt()%100;
        if(x>50) x=x-r*dX;
        if(x>50) y=y+r*ratio*dY;
            }
    default:{//正方向
        int r=randInt()%100;
        x=x+r*dX;
        y=x+r*ratio*dY;
            }

    }
    QPoint temp(x,y);
    return temp;
}


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
    for(;j<buildings.size();j++)
    {
        //传建筑位置参数
        bx=buildings.at(j)->getPosition().x();
        by=buildings.at(j)->getPosition().y();
        bw=buildings.at(j)->getWidth();
        bl=buildings.at(j)->getLength();
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
    if(p>=w)
        return;
    else
        p=p/w;
    const int distance=10;//移动距离
    int px=people[i].x();
    int py=people[i].y();
    const int where=judgeWhere(i);
    if(where>=0)//如果在建筑中
    {
        Space *b=buildings.at(where);//获取所在的建筑
        const int bx=b->getPosition().x();
        const int by=b->getPosition().y();
        const int bw=b->getWidth();
        const int bl=b->getLength();

        //禁止出界
        if(p<0.25)//右
            {
                if(px+distance<=bx+bw)//判断移动后是否出界，出了就反向走
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
    //不在各建筑中，在公共空间随即移动？还是按路径移动

}
