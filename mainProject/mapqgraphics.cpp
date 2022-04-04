#include "mapqgraphics.h"
#include <QPoint>
#include <QMouseEvent>
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

MapQGraphics::MapQGraphics(QWidget *parent) : QGraphicsView(parent)
{


}



