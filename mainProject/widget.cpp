#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置开始界面
    this->setWindowTitle("疫情模拟系统");
    this->resize(600,400);
    ui->startBtn->move(this->width()*0.5-ui->startBtn->width()*0.5,this->height()*0.6);

    //实例化主界面
    mainwin = new MainWindow;

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{
    //点击开始按钮，界面跳转
    this->hide();
    mainwin->show();
}
