#include "mapqgraphics.h"
#include <feature_timeAndStatistic/path_move.cpp>
#include <QPoint>
#include <QMouseEvent>
MapQGraphics::MapQGraphics(QWidget *parent) : QGraphicsView(parent)
{
    initPeople();//初始化人群
    initIncubation();//初始化感染潜伏者
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



