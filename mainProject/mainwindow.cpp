#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<mapqgraphics.h>
void fullOpen(MapQGraphics *);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //基本设置
    this->setWindowTitle("疫情模拟系统");
    this->resize(800,600);

    //设置状态栏
    ui->statusbar->setSizeGripEnabled(false);//去掉状态栏右下角的三角

    curlocLab = new QLabel("当前位置：",this);
    curlocLab->setMinimumWidth(200);

    curbuiLab = new QLabel("当前建筑：",this);
    curbuiLab->setMinimumWidth(180);

    ui->statusbar->addWidget(curlocLab);
    ui->statusbar->addWidget(curbuiLab);

    QLabel *permanent=new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText(tr("<a href=\"https://gitee.com/echooo294/epidemic-simulation\">代码仓库</a>"));
    permanent->setOpenExternalLinks(true);//设置可以打开网站链接
    ui->statusbar->addPermanentWidget(permanent);//显示永久信息
    //将地图上鼠标位置显示在状态栏中
    connect(ui->mapView,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(get_Mouse_Point(QPoint)));
    connect(ui->mapView,SIGNAL(mousePressPoint(QPoint)),this,SLOT(get_Mouse_Point_Press(QPoint)));
    //绘画初始化地图
    this->mapInit();

    //完全开放模拟
    ui->mapView->fullyOpen();
}

void MainWindow::mapInit()
{
    Space *r1=new Space('R',100,100,"一号居民楼",QPoint(5,5));
    Space *r2=new Space('R',100,100,"二号居民楼",QPoint(ui->mapView->width()-105,5));
    Space *r3=new Space('R',100,100,"三号居民楼",QPoint(5,ui->mapView->height()-110));
    Space *r4=new Space('R',100,100,"四号居民楼",QPoint(ui->mapView->width()-105,ui->mapView->height()-110));
    Space *w1=new Space('W',100,100,"一号写字楼",QPoint(200,100));
    Space *w2=new Space('W',100,100,"二号写字楼",QPoint(310,100));
    Space *w3=new Space('W',100,100,"三号写字楼",QPoint(200,210));
    Space *w4=new Space('W',100,100,"四号写字楼",QPoint(310,210));
    Space *h1=new Space('H',100,100,"一号医院",QPoint(5,200));
    Space *z1=new Space('Z',100,100,"一号隔离区",QPoint(ui->mapView->width()-105,200));
    Space *R[4]={r1,r2,r3,r4};
    Space *W[4]={w1,w2,w3,w4};
    Space *H[1]={h1};
    Space *Z[1]={z1};

    //初始化视图
    scene=new QGraphicsScene(0,0,ui->mapView->width()-5,ui->mapView->height()-5);
    ui->mapView->setScene(scene);
    QPen pen1,pen2,pen3,pen4;// 定义画笔，设置画笔颜色和宽度
    pen1.setColor(Qt::blue);
    pen1.setWidth(5);
    pen2.setColor(Qt::red);
    pen2.setWidth(5);
    pen3.setColor(Qt::green);
    pen3.setWidth(5);
    pen4.setColor(Qt::yellow);
    pen4.setWidth(5);

    QGraphicsRectItem *m_R = new QGraphicsRectItem[4];
    QGraphicsTextItem *t_R = new QGraphicsTextItem[4];
    QGraphicsRectItem *m_W = new QGraphicsRectItem[4];
    QGraphicsTextItem *t_W = new QGraphicsTextItem[4];
    QGraphicsRectItem *m_H = new QGraphicsRectItem[1];
    QGraphicsTextItem *t_H = new QGraphicsTextItem[1];
    QGraphicsRectItem *m_Z = new QGraphicsRectItem[1];
    QGraphicsTextItem *t_Z = new QGraphicsTextItem[1];

    for(int i=0;i<4;i++)
    {
         m_R[i].setPen(pen1);
         m_R[i].setRect(R[i]->getPosition().x(),R[i]->getPosition().y(), R[i]->getWidth(), R[i]->getLength());
         m_R[i].setData(1,R[i]->getName());
         t_R[i].setPlainText(R[i]->getName());
         t_R[i].setPos(R[i]->getPosition());
         scene->addItem(&m_R[i]);
         scene->addItem(&t_R[i]);
    }
    for(int i=0;i<4;i++)
    {
         m_W[i].setPen(pen2);
         m_W[i].setRect(W[i]->getPosition().x(),W[i]->getPosition().y(), W[i]->getWidth(), W[i]->getLength());
         m_W[i].setData(1,W[i]->getName());
         t_W[i].setPlainText(W[i]->getName());
         t_W[i].setPos(W[i]->getPosition());
         scene->addItem(&m_W[i]);
         scene->addItem(&t_W[i]);
    }
    for(int i=0;i<1;i++)
    {
         m_H[i].setPen(pen3);
         m_H[i].setRect(H[i]->getPosition().x(),H[i]->getPosition().y(), H[i]->getWidth(), H[i]->getLength());
         m_H[i].setData(1,H[i]->getName());
         t_H[i].setPlainText(H[i]->getName());
         t_H[i].setPos(H[i]->getPosition());
         scene->addItem(&m_H[i]);
         scene->addItem(&t_H[i]);
    }
    for(int i=0;i<1;i++)
    {
         m_Z[i].setPen(pen4);
         m_Z[i].setRect(Z[i]->getPosition().x(),Z[i]->getPosition().y(), Z[i]->getWidth(),Z[i]->getLength());
         m_Z[i].setData(1,Z[i]->getName());
         t_Z[i].setPlainText(Z[i]->getName());
         t_Z[i].setPos(Z[i]->getPosition());
         scene->addItem(&m_Z[i]);
         scene->addItem(&t_Z[i]);
        }
    Resident *res[400];
    for(int i=0;i<400;i++)
    {
        if(i<=100)res[i]=new Resident(this,0.3);
        else if(i<=200)res[i]=new Resident(this,0.5);
        else if(i<=400)res[i]=new Resident(this,0.7);
    }
    QGraphicsEllipseItem *people = new QGraphicsEllipseItem[400];
    QPen pen5;
    pen5.setColor(Qt::black);
    pen5.setWidth(2);
    for(int i=0;i<400;i++)
    {

        if(i<=100)
        {
            people[i].setPen(pen5);
            people[i].setRect(QRectF((i%10)*10+5,(i/10)*10+5,2,2));
            people[i].setStartAngle(16*0);
            people[i].setSpanAngle(16*360);
            scene->addItem(&people[i]);
        }
        else if(i<=200)
        {
            people[i].setPen(pen5);
            people[i].setRect(QRectF(((i-100)%10)*10+5,((i-100)/10)*10+351,2,2));
            people[i].setStartAngle(16*0);
            people[i].setSpanAngle(16*360);
            scene->addItem(&people[i]);
        }
        else if(i<=300)
        {
            people[i].setPen(pen5);
            people[i].setRect(QRectF(((i-200)%10)*10+551,((i-200)/10)*10+5,2,2));
            people[i].setStartAngle(16*0);
            people[i].setSpanAngle(16*360);
            scene->addItem(&people[i]);
        }
        else if(i<=400)
        {
            people[i].setPen(pen5);
            people[i].setRect(QRectF(((i-300)%10)*10+551,((i-300)/10)*10+351,2,2));
            people[i].setStartAngle(16*0);
            people[i].setSpanAngle(16*360);
            scene->addItem(&people[i]);
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionexit_triggered()
{
    //点击菜单中的退出，退出程序
    this->close();
}

void MainWindow::get_Mouse_Point(QPoint point)
{
    //鼠标移动事件
    int x = point.x();
    int y = point.y();
    curlocLab->setText(QString::asprintf("当前位置：%d,%d",x,y));
}

void MainWindow::get_Mouse_Point_Press(QPoint point)
{
    //鼠标单击事件
    QPointF pointScene=ui->mapView->mapToScene(point);
    QGraphicsItem *item=NULL;
    item=scene->itemAt(pointScene,ui->mapView->transform());
    if(item!=NULL)
    {
        QString str =item->data(1).toString();
        curbuiLab->setText("当前建筑："+str);
    }
//    int x = point.x();
//    int y = point.y();
//    curbuiLab->setText(QString::asprintf("当前建筑：%d,%d",x,y));
}
