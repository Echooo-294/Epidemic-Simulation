#include "contrast.h"
#include "ui_contrast.h"
#include "feature_timeAndStatistic/statistic.h"
#include <QDebug>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

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

void Contrast::pieChart(QVector<int> vec)
{
    // 构造两个饼状分区，健康人数数据显示绿色，感染人数数据显示红色
    QPieSlice *slice_1 = new QPieSlice(QStringLiteral("健康人数"), double(vec[1]), this);
    slice_1->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_1->setBrush(Qt::green);
    QPieSlice *slice_2 = new QPieSlice(QStringLiteral("感染人数"), double(vec[2]), this);
    slice_2->setLabelVisible(true);
    slice_2->setBrush(Qt::red);
    QPieSlice *slice_3 = new QPieSlice(QStringLiteral("健康人数"), double(vec[8]), this);
    slice_3->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_3->setBrush(Qt::green);
    QPieSlice *slice_4 = new QPieSlice(QStringLiteral("感染人数"), double(vec[9]), this);
    slice_4->setLabelVisible(true);
    slice_4->setBrush(Qt::red);

    // 将两个饼状分区加入series
    QPieSeries *series = new QPieSeries(this);
    series->append(slice_1);
    series->append(slice_2);
    QPieSeries *series_2 = new QPieSeries(this);
    series_2->append(slice_3);
    series_2->append(slice_4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果
    QChart *chart_2 = new QChart();
    chart_2->addSeries(series_2);
    chart_2->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果

    QChartView *chartview = new QChartView(this);
    chartview->show();
    chartview->setChart(chart);
    QChartView *chartview_2 = new QChartView(this);
    chartview_2->show();
    chartview_2->setChart(chart_2);

    ui->verticalLayout_4->insertWidget(0, chartview);
    ui->verticalLayout_5->insertWidget(0, chartview_2);
}

void Contrast::barChart(QVector<int> vec)
{
    QBarSet *set0 = new QBarSet("健康人数");
    QBarSet *set1 = new QBarSet("感染人数");
    QBarSet *set2 = new QBarSet("重症人数");
    QBarSet *set3 = new QBarSet("死亡人数");
    QBarSet *set4 = new QBarSet("疫苗接种人数");

    *set0 << vec[1] << vec[8];
    *set1 << vec[2] << vec[9];
    *set2 << vec[3] << vec[10];
    *set3 << vec[4] << vec[11];
    *set4 << vec[5] << vec[12];

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("不同政策各人群对比图");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QStringList categories;
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    categories << ui->label->text() << ui->label_2->text();
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,initPopulation);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ui->verticalLayout->insertWidget(0, chartView);
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

    pieChart(vec);
    barChart(vec);

}
