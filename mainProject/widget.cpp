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
    ui->label->move(this->width()*0.5-ui->label->width()*0.5+150,this->height()*0.05);

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
    initpopline->setText("1000");
    //感染人数
    initinflab=new QLabel(this);
    initinfline=new QLineEdit(this);
    initinflab->setFont(font2);
    initinflab->setText("初始感染人数");
    initinflab->move(this->width()*0.25,this->height()*0.4+50);
    initinfline->setGeometry(this->width()*0.25+150,this->height()*0.4+50,100,initinflab->height());
    initinfline->setText("3");
    //政策
    initpollab=new QLabel(this);
    initpolBox=new QComboBox(this);
    initpollab->setFont(font2);
    initpollab->setText("初始政策");
    initpolBox->addItem("完全开放");
    initpolBox->addItem("接种疫苗+基本不管控");
    initpolBox->addItem("接种疫苗+戴口罩+适度管控");
    initpolBox->addItem("接种疫苗+戴口罩+严格管控");
    initpollab->move(this->width()*0.25,this->height()*0.4+100);
    initpolBox->setGeometry(this->width()*0.25+150,this->height()*0.4+100,initpolBox->width()+100,initinflab->height());

    //左上角校徽
    QPixmap pix(":/images/sclbadge.png");
    QSize siz(80,80);
    pix=pix.scaled(siz,Qt::KeepAspectRatio);
    QLabel *scl=new QLabel(this);
    scl->setPixmap(pix);
    scl->move(15,10);

    //右下角版本
    QLabel *version=new QLabel(this);
    version->setText("v1.0");
    version->move(this->width()-version->width()+50,this->height()-20);
    //用于保存统计量的组别数目
    vec.resize(15);
    vec[0]=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::record()
{
    //记录上一次模拟的统计量
    int i=vec.at(0);
    vec[i*7+1]=healthNumber;
    vec[i*7+2]=infectionNumber;
    vec[i*7+3]=seriousNumber;
    vec[i*7+4]=deadNumber;
    vec[i*7+5]=immunityNumber;
    vec[i*7+6]=day;
    vec[i*7+7]=policy;
    vec[0]=(i+1)%2;
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
    //传总人数数据和感染人数数据
    initPopulation=initpopline->text().toInt();
    initInfection=initinfline->text().toInt();

    healthNumber=initPopulation-initInfection;
    infectionNumber=initInfection;
    isolationNumber=0;
    seriousNumber=0;
    deadNumber=0;
    immunityNumber=0;
    day=1;
    showTime=0;
    policy=initpolBox->currentIndex();
    //点击开始按钮，界面跳转
    this->close();
    //实例化主界面
    mainwin = new MainWindow;
    mainwin->show();

    connect(mainwin,&MainWindow::emitExit,this,[=](){
        mainwin->hide();
        this->show();
        delete mainwin;
        record();
    });
}
