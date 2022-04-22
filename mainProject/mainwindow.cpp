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
    this->resize(1600,1000);
    //界面布局
    ui->groupBox->setGeometry(0,0,this->width(),this->height()*0.2);
    ui->groupBox_3->setGeometry(0,this->height()*0.2,this->width(),this->height()*0.8);
    ui->groupBox_2->setGeometry(0,0,ui->groupBox_3->width()*0.2,ui->groupBox_3->height());
    ui->mapView->setGeometry(this->width()*0.2,0,ui->groupBox_3->width()*0.8,ui->groupBox_3->height()-50);

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
    //模拟疫情开始
    ui->mapView->fullyOpen();
}

void MainWindow::showStatistic1()
{

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
