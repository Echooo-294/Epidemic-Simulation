#ifndef MAPQGRAPHICS_H
#define MAPQGRAPHICS_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <feature_space/space.h>
#include<QVector>

class MapQGraphics : public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event) override;//鼠标移动事件重写
    void mousePressEvent(QMouseEvent *event) override;//鼠标按下事件重写
public:
    MapQGraphics(QWidget *parent = nullptr);
    QVector<Resident*> allPeople;//总人群数组
    QVector<Resident*> incubations;//感染潜伏数组
    void initPeople();//初始化全部人群，用在构造函数中
    void initIncubation();//初始化潜伏感染者，用在构造函数中
    void fullyOpen();//完全开放模拟
    void simulation1();//完全开放模拟每半小时的过程


signals:
    void mouseMovePoint(QPoint point);//发送鼠标移动信号，传坐标
    void mousePressPoint(QPoint point);//发送鼠标按下信号，传坐标
};

#endif // MAPQGRAPHICS_H
