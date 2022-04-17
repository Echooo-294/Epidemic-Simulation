/*
 * @Description: 主界面，最近修改mapInit：添加各大建筑类进入mapView
 * @Date: 2022-04-04
 * @Last Modified by: echooo
 * @Last Modified time: 2022-04-12
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<mapqgraphics.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //基本设置
    this->setWindowTitle("疫情模拟系统");
    this->resize(1200,800);
    //界面布局
    ui->groupBox->setGeometry(0,0,this->width(),this->height()*0.15);
    ui->groupBox_3->setGeometry(0,this->height()*0.15,this->width(),this->height()*0.85);
    ui->groupBox_2->setGeometry(0,0,ui->groupBox_3->width()*0.15,ui->groupBox_3->height());
    ui->mapView->setGeometry(this->width()*0.15,0,ui->groupBox_3->width()*0.85,ui->groupBox_3->height()-50);
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


}

void MainWindow::mapInit()
{
    //初始化一系列建筑
    //继续添加建筑需要去修改statistic.cpp中的buildingNumber
    Space *r1=new Space('R',150,200,"一号居民楼",QPoint(5,5));
    ui->mapView->buildings[0]=r1;
    Space *r2=new Space('R',150,200,"二号居民楼",QPoint(ui->mapView->width()-455,5));
    ui->mapView->buildings[1]=r2;
    Space *r3=new Space('R',150,200,"三号居民楼",QPoint(5,ui->mapView->height()-160));
    ui->mapView->buildings[2]=r3;
    Space *r4=new Space('R',150,200,"四号居民楼",QPoint(ui->mapView->width()-455,ui->mapView->height()-160));
    ui->mapView->buildings[3]=r4;
    Space *w1=new Space('W',200,200,"一号写字楼",QPoint(270,210));
    ui->mapView->buildings[4]=w1;
    //    Space *w2=new Space('W',100,100,"二号写字楼",QPoint(1,1));
    //    Space *w3=new Space('W',100,100,"三号写字楼",QPoint(1,1));
    //    Space *w4=new Space('W',100,100,"四号写字楼",QPoint(1,1));
    Space *h1=new Space('H',300,235,"一号医院",QPoint(ui->mapView->width()-240,5));
    ui->mapView->buildings[5]=h1;
    Space *z1=new Space('Z',300,235,"一号隔离区",QPoint(ui->mapView->width()-240,ui->mapView->height()-305));
    ui->mapView->buildings[6]=z1;
    Space *R[4]={r1,r2,r3,r4};
    Space *W[4]={w1};
    Space *H[1]={h1};
    Space *Z[1]={z1};

    //初始化视图
    scene=new QGraphicsScene(0,0,ui->mapView->width()-5,ui->mapView->height()-5);
    ui->mapView->setScene(scene);

    auto line = new QGraphicsLineItem;
    line->setLine(ui->mapView->width()-250,0,ui->mapView->width()-250,ui->mapView->height());
    QPen pen6;
    pen6.setWidth(2);
    pen6.setColor(Qt::black);
    line->setPen(pen6);
    scene->addItem(line);

    QPen pen1,pen2,pen3,pen4;
    // 定义画笔，设置画笔颜色和宽度
    pen1.setColor(Qt::blue);
    pen1.setWidth(5);
    pen2.setColor(Qt::red);
    pen2.setWidth(5);
    pen3.setColor(Qt::green);
    pen3.setWidth(5);
    pen4.setColor(Qt::yellow);
    pen4.setWidth(5);

    //为各种建筑类建立图元
    QGraphicsRectItem *m_R = new QGraphicsRectItem[4];
    QGraphicsTextItem *t_R = new QGraphicsTextItem[4];
    QGraphicsRectItem *m_W = new QGraphicsRectItem[1];
    QGraphicsTextItem *t_W = new QGraphicsTextItem[1];
    QGraphicsRectItem *m_H = new QGraphicsRectItem[1];
    QGraphicsTextItem *t_H = new QGraphicsTextItem[1];
    QGraphicsRectItem *m_Z = new QGraphicsRectItem[1];
    QGraphicsTextItem *t_Z = new QGraphicsTextItem[1];

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
        scene->addItem(&m_R[i]);
        scene->addItem(&t_R[i]);
    }
    for(int i=0;i<1;i++)
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

    //将居民放进不同的居民楼里
    for(int i=0;i<400;i++)
    {
        ui->mapView->people[i].setData(1,"jiankang");
        if(i<100)
        {
            ui->mapView->people[i].setBrush(QBrush(Qt::green));
            ui->mapView->people[i].setRect(QRectF(0,0,7,7));// 坐标(可以用随机数生成坐标让居民不用排的整整齐齐)，高，宽
            ui->mapView->people[i].setStartAngle(16*0);//起始角度
            ui->mapView->people[i].setSpanAngle(16*360);//旋转角度
            ui->mapView->people[i].setPos((i%10)*20+10+r1->getPosition().x(),(i/10)*15+7+r1->getPosition().y());
            scene->addItem(&ui->mapView->people[i]);
        }
        else if(i<200)
        {
            ui->mapView->people[i].setBrush(QBrush(Qt::green));
            ui->mapView->people[i].setRect(QRectF(0,0,7,7));
            ui->mapView->people[i].setStartAngle(16*0);
            ui->mapView->people[i].setSpanAngle(16*360);
            ui->mapView->people[i].setPos(((i-100)%10)*20+10+r2->getPosition().x(),((i-100)/10)*15+7+r2->getPosition().y());
            scene->addItem(&ui->mapView->people[i]);
        }
        else if(i<300)
        {
            ui->mapView->people[i].setBrush(QBrush(Qt::green));
            ui->mapView->people[i].setRect(QRectF(0,0,7,7));
            ui->mapView->people[i].setStartAngle(16*0);
            ui->mapView->people[i].setSpanAngle(16*360);
            ui->mapView->people[i].setPos(((i-200)%10)*20+10+r3->getPosition().x(),((i-200)/10)*15+7+r3->getPosition().y());
            scene->addItem(&ui->mapView->people[i]);
        }
        else if(i<400)
        {
            ui->mapView->people[i].setBrush(QBrush(Qt::green));
            ui->mapView->people[i].setRect(QRectF(0,0,7,7));
            ui->mapView->people[i].setStartAngle(16*0);
            ui->mapView->people[i].setSpanAngle(16*360);
            ui->mapView->people[i].setPos(((i-300)%10)*20+10+r4->getPosition().x(),((i-300)/10)*15+7+r4->getPosition().y());
            scene->addItem(&ui->mapView->people[i]);
        }
    }

    for(int i=0;i<initInfection;i++)//初始的感染者全部是感染潜伏
    {
        ui->mapView->people[i].setHealthStatus(1);//全体人群从0开始感染
        ui->mapView->people[i].setData(1,"ganran");
        ui->mapView->people[i].setBrush(Qt::red);
        ui->mapView->incubation[i].setHealthStatus(1);
    }


    //模拟疫情开始
    ui->mapView->fullyOpen();
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
}
