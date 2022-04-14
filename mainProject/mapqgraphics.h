#ifndef MAPQGRAPHICS_H
#define MAPQGRAPHICS_H

#include <QObject>
#include <QPoint>
#include<QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <feature_space/space.h>

#include<mainwindow.h>

class MapQGraphics : public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event) override;//鼠标移动事件重写
    void mousePressEvent(QMouseEvent *event) override;//鼠标按下事件重写
public:
    MapQGraphics(QWidget *parent = nullptr);
    //建筑、人群、感染容器
    QVector<Space*> buildings;//存放所有建筑
    QVector<Resident*> allPeople;//总人群数组
    QVector<Resident*> incubations;//感染潜伏数组

    Resident *people;//人群图元，目前是400个
    Resident *infectpeople;
    //定时器
    QTimer *timer1;//定时器1，用来模拟每半小时的
    QTimer *timer2;//定时器2，用来模拟每天的统计结果更新
    QTimer *timer3;//


    //初始化，实现在init.cpp中
    void initPeople();//初始化全部人群，用在构造函数中
    void initIncubation();//初始化潜伏感染者，用在构造函数中
    //开放模拟，实现在fullyOpen中
    void fullyOpen();//完全开放模拟
    void simulation1();//完全开放模拟每半小时的过程
    //涉及居民移动，实现在move.cpp中
    int judgeWhere(int i);//判断人在第几个建筑中，可以根据模拟活动简化判断，如果都不在则返回-1
    void randMove(int i);//随即移动，不在建筑中的随机移动还没写
    //在路径上的移动，还未实现
    void path();//路径移动
signals:
    void mouseMovePoint(QPoint point);//发送鼠标移动信号，传坐标
    void mousePressPoint(QPoint point);//发送鼠标按下信号，传坐标
};

#endif // MAPQGRAPHICS_H
