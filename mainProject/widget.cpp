#include "widget.h"
#include "ui_widget.h"
#include <QFont>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置开始界面
    this->setWindowTitle("疫情模拟系统");
    this->resize(600,400);
    //开始按钮
    ui->startBtn->move(this->width()*0.5-ui->startBtn->width()*0.5,this->height()*0.5);
    ui->startBtn->setIcon(QIcon(":/images/strBtn.png"));
    ui->startBtn->setIconSize(ui->startBtn->size());
    this->setStyleSheet("QPushButton{border:0px;}");

    //界面大标题
    //设置字体
    QFont font = ui->label->font();
    font.setPointSize(48);
    font.setFamily(QStringLiteral("宋体"));
    ui->label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{
    //点击开始按钮，界面跳转
    this->hide();
    //实例化主界面
    mainwin = new MainWindow;
    mainwin->show();
}
