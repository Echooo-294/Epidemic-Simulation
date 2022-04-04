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

MapQGraphics::MapQGraphics(QWidget *parent) : QGraphicsView(parent)
{


}



