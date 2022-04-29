#include "contrast.h"
#include "ui_contrast.h"
#include <QDebug>
Contrast::Contrast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contrast)
{
    ui->setupUi(this);

    this->setWindowTitle("对比");
}

void Contrast::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    emit emitExit();
}

Contrast::~Contrast()
{
    delete ui;
}

void Contrast::get_init(QVector<int> vec)
{
    ui->lineEdit->setText(QString::number(vec[1]));
    ui->lineEdit_2->setText(QString::number(vec[2]));
    ui->lineEdit_3->setText(QString::number(vec[3]));
    ui->lineEdit_4->setText(QString::number(vec[4]));
    ui->lineEdit_5->setText(QString::number(vec[5]));
    ui->lineEdit_6->setText(QString::number(vec[6]));
    switch(vec[7])
    {
    case 1:ui->label->setText("完全开放");break;
    case 2:ui->label->setText("接种疫苗+基本不管控");break;
    case 3:ui->label->setText("接种疫苗+戴口罩+适度管控");break;
    case 4:ui->label->setText("接种疫苗+戴口罩+严格管控");break;
    default: ui->label->setText(" ");
    }
    ui->lineEdit_7->setText(QString::number(vec[8]));
    ui->lineEdit_8->setText(QString::number(vec[9]));
    ui->lineEdit_9->setText(QString::number(vec[10]));
    ui->lineEdit_10->setText(QString::number(vec[11]));
    ui->lineEdit_11->setText(QString::number(vec[12]));
    ui->lineEdit_12->setText(QString::number(vec[13]));
    switch(vec[14])
    {
    case 1:ui->label_2->setText("完全开放");break;
    case 2:ui->label_2->setText("接种疫苗+基本不管控");break;
    case 3:ui->label_2->setText("接种疫苗+戴口罩+适度管控");break;
    case 4:ui->label_2->setText("接种疫苗+戴口罩+严格管控");break;
    default: ui->label_2->setText(" ");
    }




}
