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

    //在主窗口左部上每2h更新统计结果,包括显示人数和视图
    timer1=new QTimer(this);//初始化计时器
    connect(timer1,&QTimer::timeout,this,&MainWindow::everyday);
    timer1->start(ui->mapView->interval);//代表2小时

    //在主窗口上方添加图表，展示每日各个人群状态
    chart = new Chart;
    //chart->setTitle("累计健康/累计感染");//设置图表名称
    //chart->legend()->hide();
    chart->legend()->setAlignment(Qt::AlignRight);//在图表右侧显示曲线名称
    chart->setAnimationOptions(QChart::AllAnimations);//设置图表动画效果
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);//设置抗锯齿，让曲线看起来更加平滑
    //ui->graphicsView->setRubberBand(QChartView::HorizontalRubberBand);实现放大功能



}

void MainWindow::mapInit()
{
    //模拟疫情开始
    switch(policy)
    {
    case 0:ui->mapView->fullyOpen();break;
    case 1:ui->mapView->policy2();break;
    case 2:ui->mapView->policy3();break;
    case 3:ui->mapView->policy4();
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
    item=ui->mapView->scene->itemAt(pointScene,ui->mapView->transform());
    if(item!=NULL)
    {
        QString str =item->data(1).toString();
        curbuiLab->setText("当前建筑："+str);
    }
}

//暂停按钮
void MainWindow::on_pushButton_clicked()
{
    ui->mapView->timer1->stop();
    ui->mapView->timer2->stop();
    chart->m_timer.stop();
}
//开始按钮
void MainWindow::on_pushButton_2_clicked()
{
    ui->mapView->timer1->start();
    ui->mapView->timer2->start();
    chart->m_timer.start();
}
//加速调节
void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    //调节定时器间隔达到加速的效果
    ui->mapView->timer1->setInterval(ui->mapView->interval/arg1.toFloat());
    ui->mapView->timer2->setInterval((ui->mapView->interval/arg1.toFloat())*12);
    chart->m_timer.setInterval((ui->mapView->interval/arg1.toFloat())*12);
}

void MainWindow::on_actexit_triggered()
{
    emit emitExit();
}
