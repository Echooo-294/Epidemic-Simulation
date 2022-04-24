#ifndef MAPQGRAPHICS_H
#define MAPQGRAPHICS_H

#include <QObject>
#include <QPoint>
#include <QtDebug>
#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemAnimation>
#include <feature_space/space.h>
#include <feature_resident/resident.h>

#include<mainwindow.h>
#include<widget.h>

class MapQGraphics : public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event) override;//鼠标移动事件重写
    void mousePressEvent(QMouseEvent *event) override;//鼠标按下事件重写
public:
    MapQGraphics(QWidget *parent = nullptr);
    //建筑、人群、感染潜伏数组，都在构造函数中初始化
    Space** buildings;//存放所有建筑
    Resident *people;//人群图元，目前是400个
    Resident *incubation;//感染潜伏人群
    //定时器
    QTimer *timer1;//模拟每隔一定时间的更新
    QTimer *timer2;//模拟每天的统计结果更新
    int interval;//每次更新的时间间隔，默认2小时-400ms
    //建筑图元和名称定义
    QGraphicsRectItem *m_R,*m_W,*m_H,*m_Z;
    QGraphicsTextItem *t_R,*t_W,*t_H,*t_Z;
    //场景
    QGraphicsScene *scene;
    //开放模拟，实现在fullyOpen中
    void fullyOpen();//完全开放模拟
    void simulation1();//完全开放模拟每半小时的过程
    //涉及居民移动，实现在move.cpp中
    int judgeWhere(int i);//判断人在第几个建筑中，可以根据模拟活动简化判断，如果都不在则返回-1
    //随机移动，不在建筑中的随机移动还没写
    void randMove(int i);
    //在路径上的移动，还未实现
    void path();//路径移动
    //封装动画移动函数,在move.cpp中实现
    void moveSilky(int i,QPoint des,int t);
    //每天的病毒自然增长和治疗
    void everyday();
    //感染，实现在feature_virus/infecting.cpp
    bool judgeInfected(int i,int j);//计算感染概率
    void infecting1(int i);//由感染者去感染他人，调用前需要确定是感染者
signals:
    void mouseMovePoint(QPoint point);//发送鼠标移动信号，传坐标
    void mousePressPoint(QPoint point);//发送鼠标按下信号，传坐标
private slots:
    void getinitdata(int,int,QString);
};

#endif // MAPQGRAPHICS_H
