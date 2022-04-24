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
    this->resize(600,500);
    //开始按钮
    ui->startBtn->move(this->width()*0.5-ui->startBtn->width()*0.5,this->height()*0.6+50);
    ui->startBtn->setIcon(QIcon(":/images/strBtn.png"));
    ui->startBtn->setIconSize(ui->startBtn->size());
    this->setStyleSheet("QPushButton{border:0px;}");

    //界面大标题
    //设置字体
    QFont font = ui->label->font();
    font.setPointSize(40);
    font.setFamily(QStringLiteral("宋体"));
    ui->label->setFont(font);
    ui->label->move(this->width()*0.5-ui->label->width()*0.5+100,this->height()*0.05);

    //设置初始化
    QFont font2;
    font2.setPointSize(15);
    //总人数
    initpoplab=new QLabel(this);
    initpopline=new QLineEdit(this);
    initpoplab->setFont(font2);
    initpoplab->setText("初始总人数");
    initpoplab->move(this->width()*0.25,this->height()*0.4);
    initpopline->setGeometry(this->width()*0.25+150,this->height()*0.4,100,initpoplab->height());
    //感染人数
    initinflab=new QLabel(this);
    initinfline=new QLineEdit(this);
    initinflab->setFont(font2);
    initinflab->setText("初始感染人数");
    initinflab->move(this->width()*0.25,this->height()*0.4+50);
    initinfline->setGeometry(this->width()*0.25+150,this->height()*0.4+50,100,initinflab->height());
    //政策
    initpollab=new QLabel(this);
    initpolBox=new QComboBox(this);
    initpollab->setFont(font2);
    initpollab->setText("初始政策");
    initpolBox->addItem("完全开放");
    initpollab->move(this->width()*0.25,this->height()*0.4+100);
    initpolBox->setGeometry(this->width()*0.25+150,this->height()*0.4+100,initpolBox->width(),initinflab->height());

    //左上角校徽
    QPixmap pix(":/images/sclbadge.png");
    QSize siz(80,80);
    pix=pix.scaled(siz,Qt::KeepAspectRatio);
    QLabel *scl=new QLabel(this);
    scl->setPixmap(pix);
    scl->move(15,10);

    //右下角版本
    QLabel *version=new QLabel(this);
    version->setText("v0.5");
    version->move(this->width()-version->width()+50,this->height()-20);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{
    //首先判断两个输入框状态
    if(initpopline->text().isEmpty()||initinfline->text().isEmpty()){
        QMessageBox::warning(this,QString("警告！"),QString("请输入总人数或感染人数"));
        return;
    }
    else if(initinfline->text().toInt()>initpopline->text().toInt()){
        QMessageBox::warning(this,QString("警告！"),QString("感染人数超过总人数"));
        return;
    }
    //数据无误，发射信号
    emit initdata(initpopline->text().toInt(),initinfline->text().toInt(),initpolBox->currentText());
    //点击开始按钮，界面跳转
    this->hide();
    //实例化主界面
    mainwin = new MainWindow;
    mainwin->show();
    connect(this,SIGNAL(initdata(int,int,QString)),mainwin,SLOT(bridgeRec(int,int,QString)));
}
