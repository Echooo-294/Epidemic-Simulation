#include "mapqgraphics.h"
#include <QPoint>
#include <QMouseEvent>
MapQGraphics::MapQGraphics(QWidget *parent) : QGraphicsView(parent)
{
    //initPopulation是定义在statistic.cpp中的初始总人数
    people = new Resident[initPopulation];
    for(int i=0;i<initPopulation;i++)//初始化居民
    {
        Resident adult;
        people[i]=adult;
    }

    //initInfection是定义在statistic.cpp中的初始感染人数
    incubation = new Resident[initPopulation];//给感染者数组直接构造initPopulation的空间，避免超量
    for(int i=0;i<initInfection;i++)//初始的感染者全部是感染潜伏
    {
        people[i].setHealthStatus(1);//全体人群从0开始感染
        people[i].setVirusDensity(0.03);//赋予初始病毒密度
        incubation[i]=people[i];//并且添加到感染潜伏数组
    }
    //buildingNumber是定义在statistic.cpp中的建筑数量
    buildings = new Space*[buildingNumber];
}

void MapQGraphics::mouseMoveEvent(QMouseEvent *event)
{
    //鼠标移动
    QPoint point=event->pos();
    emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}

void MapQGraphics::mousePressEvent(QMouseEvent *event)
{
    //鼠标点击
    QPoint point=event->pos();
    emit mousePressPoint(point);
    QGraphicsView::mousePressEvent(event);
}
void MapQGraphics::path()
{

}



