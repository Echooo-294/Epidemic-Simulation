#ifndef MAPQGRAPHICS_H
#define MAPQGRAPHICS_H

#include <QObject>
#include <QGraphicsView>

class MapQGraphics : public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event) override;//鼠标移动事件重写
    //void mousePressEvent(QMouseEvent *event) override;
public:
    MapQGraphics(QWidget *parent = nullptr);

signals:
    void mouseMovePoint(QPoint point);
};

#endif // MAPQGRAPHICS_H
