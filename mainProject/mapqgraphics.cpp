#include "mapqgraphics.h"
#include <QPoint>
#include <QMouseEvent>
MapQGraphics::MapQGraphics(QWidget *parent) : QGraphicsView(parent)
{
    //初始化图形大小
    this->resize(1280,750);
    //initPopulation是定义在statistic.cpp中的初始总人数
    people = new Resident[initPopulation];
    int i=0;
    for(;i<initPopulation;i++)//初始化居民
    {
        Resident adult;
        people[i]=adult;
        people[i].setBrush(QBrush(Qt::green));
    }

    //initInfection是定义在statistic.cpp中的初始感染人数
    incubation = new Resident[initPopulation];//给感染者数组直接构造initPopulation的空间，避免超量
    for(int i=0;i<initInfection;i++)//初始的感染者全部是感染潜伏
    {
        people[i].setHealthStatus(1);//全体人群从0开始感染
        people[i].setVirusDensity(0.03);//赋予初始病毒密度
        people[i].setData(1,"infected");//设置被感染的标志
        people[i].setBrush(QBrush(Qt::red));//变红
        incubation[i]=people[i];//并且添加到感染潜伏数组
    }

    //buildingNumber是定义在statistic.cpp中的建筑数量
    buildings = new Space*[buildingNumber];

    //初始化视图
    scene=new QGraphicsScene(0,0,this->width()-5,this->height()-5);
    this->setScene(scene);

    auto line = new QGraphicsLineItem;
    line->setLine(this->width()-195,0,this->width()-195,this->height());
    QPen pen6;
    pen6.setWidth(2);
    pen6.setColor(Qt::black);
    line->setPen(pen6);
    scene->addItem(line);

    //初始化一系列建筑
    //继续添加建筑需要去修改statistic.cpp中的buildingNumber
    Space *r1=new Space('R',150,200,"一号居民楼",QPoint(5,5));
    this->buildings[0]=r1;
    Space *r2=new Space('R',150,200,"二号居民楼",QPoint(this->width()-400,5));
    this->buildings[1]=r2;
    Space *r3=new Space('R',150,200,"三号居民楼",QPoint(5,this->height()-160));
    this->buildings[2]=r3;
    Space *r4=new Space('R',150,200,"四号居民楼",QPoint(this->width()-400,this->height()-160));
    this->buildings[3]=r4;
    Space *w1=new Space('W',200,200,"一号写字楼",QPoint(this->width()*0.5-100,this->height()*0.5-100));
    this->buildings[4]=w1;
    //    Space *w2=new Space('W',100,100,"二号写字楼",QPoint(1,1));
    //    Space *w3=new Space('W',100,100,"三号写字楼",QPoint(1,1));
    //    Space *w4=new Space('W',100,100,"四号写字楼",QPoint(1,1));
    Space *h1=new Space('H',300,180,"一号医院",QPoint(this->width()-185,5));
    this->buildings[5]=h1;
    Space *z1=new Space('Z',300,180,"一号隔离区",QPoint(this->width()-185,this->height()-305));
    this->buildings[6]=z1;
    Space *R[4]={r1,r2,r3,r4};
    Space *W[4]={w1};
    Space *H[1]={h1};
    Space *Z[1]={z1};

    QPen pen1,pen2,pen3,pen4;
    // 定义画笔，设置画笔颜色和宽度
    //居民楼用
    pen1.setColor(Qt::blue);
    pen1.setWidth(5);
    //写字楼用
    pen2.setColor(Qt::red);
    pen2.setWidth(5);
    //医院用
    pen3.setColor(Qt::green);
    pen3.setWidth(5);
    //隔离区用
    pen4.setColor(Qt::yellow);
    pen4.setWidth(5);

    //建筑图元初始化
    //居民楼
    m_R = new QGraphicsRectItem[4];
    t_R = new QGraphicsTextItem[4];
    //写字楼
    m_W = new QGraphicsRectItem[1];
    t_W = new QGraphicsTextItem[1];
    //医院
    m_H = new QGraphicsRectItem[1];
    t_H = new QGraphicsTextItem[1];
    //隔离区
    m_Z = new QGraphicsRectItem[1];
    t_Z = new QGraphicsTextItem[1];

    //在主界面中绘图
    for(int i=0;i<4;i++)
    {
        m_R[i].setPen(pen1);
        //m_R[i].setFlag(QGraphicsItem::ItemIsMovable);
        //获取建筑参数，绘画矩形建筑
        m_R[i].setRect(R[i]->getPosition().x(),R[i]->getPosition().y(), R[i]->getWidth(), R[i]->getLength());
        m_R[i].setData(1,R[i]->getName());
        t_R[i].setPlainText(R[i]->getName());//添加建筑文字内容
        t_R[i].setPos(R[i]->getPosition());
        scene->addItem(&this->m_R[i]);
        scene->addItem(&this->t_R[i]);
    }
    for(int i=0;i<1;i++)
    {
        m_W[i].setPen(pen2);
        m_W[i].setRect(W[i]->getPosition().x(),W[i]->getPosition().y(), W[i]->getWidth(), W[i]->getLength());
        m_W[i].setData(1,W[i]->getName());
        t_W[i].setPlainText(W[i]->getName());
        t_W[i].setPos(W[i]->getPosition());
        scene->addItem(&this->m_W[0]);
        scene->addItem(&this->t_W[0]);
    }
    for(int i=0;i<1;i++)
    {
        m_H[i].setPen(pen3);
        m_H[i].setRect(H[i]->getPosition().x(),H[i]->getPosition().y(), H[i]->getWidth(), H[i]->getLength());
        m_H[i].setData(1,H[i]->getName());
        t_H[i].setPlainText(H[i]->getName());
        t_H[i].setPos(H[i]->getPosition());
        scene->addItem(&this->m_H[0]);
        scene->addItem(&this->t_H[0]);
    }
    for(int i=0;i<1;i++)
    {
        m_Z[i].setPen(pen4);
        m_Z[i].setRect(Z[i]->getPosition().x(),Z[i]->getPosition().y(), Z[i]->getWidth(),Z[i]->getLength());
        m_Z[i].setData(1,Z[i]->getName());
        t_Z[i].setPlainText(Z[i]->getName());
        t_Z[i].setPos(Z[i]->getPosition());
        scene->addItem(&this->m_Z[0]);
        scene->addItem(&this->t_Z[0]);
    }

    //把居民放进居民楼
    const int r=4;//人图元的直径
    for(int i=0;i<initPopulation;i++)
    {
        if(i<100)
        {
            this->people[i].setRect(QRectF(0,0,r,r));// 坐标(可以用随机数生成坐标让居民不用排的整整齐齐)，高，宽
            this->people[i].setStartAngle(16*0);//起始角度
            this->people[i].setSpanAngle(16*360);//旋转角度
            this->people[i].setPos((i%10)*20+10+r1->getPosition().x(),(i/10)*15+7+r1->getPosition().y());
        }
        else if(i<200)
        {
            this->people[i].setRect(QRectF(0,0,r,r));
            this->people[i].setStartAngle(16*0);
            this->people[i].setSpanAngle(16*360);
            this->people[i].setPos(((i-100)%10)*20+10+r2->getPosition().x(),((i-100)/10)*15+7+r2->getPosition().y());
        }
        else if(i<300)
        {
            this->people[i].setRect(QRectF(0,0,r,r));
            this->people[i].setStartAngle(16*0);
            this->people[i].setSpanAngle(16*360);
            this->people[i].setPos(((i-200)%10)*20+10+r3->getPosition().x(),((i-200)/10)*15+7+r3->getPosition().y());
        }
        else if(i<400)
        {
            this->people[i].setRect(QRectF(0,0,r,r));
            this->people[i].setStartAngle(16*0);
            this->people[i].setSpanAngle(16*360);
            this->people[i].setPos(((i-300)%10)*20+10+r4->getPosition().x(),((i-300)/10)*15+7+r4->getPosition().y());
        }
    }
   //添加居民图元到场景中
    for(int i=0;i<initPopulation;i++)
        scene->addItem(&this->people[i]);


    interval=400;//400ms
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




