/*
 * @Description: 图表类的实现
 * @Author: 巾可
 * @Date: 2022-04-23
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-04-24
 */

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
#include <feature_timeAndStatistic/statistic.h>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_series2(0),
    m_series3(0),
    m_axisX(new QValueAxis()),//x坐标轴初始化
    m_axisY(new QValueAxis()),//y坐标轴初始化
    m_step(0),
    m_x(0),//初始点x坐标值
    m_y(0),//初始点y坐标值
    m_y2(400),//初始点y2坐标值
    m_y3(0)//初始点y3坐标值
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
    m_timer.setInterval(4800);//设置更新时间间隔，现在默认为一天2400ms

    //感染人数每日变化曲线设置为红色
    m_series = new QSplineSeries(this);
    QPen red(Qt::red);
    red.setWidth(1);//设置曲线宽度
    m_series->setPen(red);
    m_series->append(m_x, m_y);//加入初始点
    m_series->setName("感染人数");

    //健康人数每日变化曲线设置为蓝色
    m_series2 = new QSplineSeries(this);
    QPen blue(Qt::blue);
    blue.setWidth(1);//设置曲线宽度
    m_series2->setPen(blue);
    m_series2->append(m_x, m_y2);//加入初始点
    m_series2->setName("健康人数");

    //死亡人数每日变化曲线设置为紫色
    m_series3 = new QSplineSeries(this);
    QPen x(QColor(255,0,255));
    blue.setWidth(1);//设置曲线宽度
    m_series3->setPen(x);
    m_series3->append(m_x, m_y3);//加入初始点
    m_series3->setName("死亡人数");

    addSeries(m_series);
    addSeries(m_series2);
    addSeries(m_series3);
    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);

    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_series2->attachAxis(m_axisX);
    m_series2->attachAxis(m_axisY);
    m_series3->attachAxis(m_axisX);
    m_series3->attachAxis(m_axisY);

    //可以理解为设置刻度格数
    m_axisX->setTickCount(8);
    m_axisY->setTickCount(6);
    m_axisX->setRange(0, 7);//设置x坐标轴的范围
    m_axisY->setRange(0, 500);//设置y坐标轴的范围

    m_timer.start();
}

Chart::~Chart()
{

}

void Chart::handleTimeout()
{
    qreal x = plotArea().width() / (m_axisX->tickCount()-1);//设置坐标轴每次回滚的距离
    qDebug()<<m_axisX->tickCount();
    //qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();//x每次移动的距离
    //qDebug()<< plotArea().width()<<m_axisX->max()<<m_axisX->min()<< m_axisX->tickCount();
    m_x += 1;
    m_y = infectionNumber;/*QRandomGenerator::global()->bounded(5) - 2.5;*/
    m_y2 = healthNumber;
    m_y3 = deadNumber;
    //增加新增的点，连接成曲线
    m_series->append(m_x, m_y);
    m_series2->append(m_x, m_y2);
    m_series3->append(m_x, m_y3);
    //设置回滚，让线条变化处于中心位置
    if(m_x>=5)
        scroll(x, 0);
    //暂停条件，m_x即天数大于300时停止
    if (m_x >= 300)
        m_timer.stop();
}

