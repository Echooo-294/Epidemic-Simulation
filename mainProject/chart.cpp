#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
#include<feature_timeAndStatistic/statistic.h>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_series2(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(0),
    m_y(0),
    m_y2(400)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
    m_timer.setInterval(2400);//设置更新时间间隔，现在默认为一天2400ms

    m_series = new QSplineSeries(this);
    QPen red(Qt::red);
    red.setWidth(3);
    m_series->setPen(red);
    m_series->append(m_x, m_y);

    m_series2 = new QSplineSeries(this);
    QPen blue(Qt::blue);
    blue.setWidth(3);
    m_series2->setPen(blue);
    m_series2->append(m_x, m_y2);

    addSeries(m_series);
    addSeries(m_series2);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_series2->attachAxis(m_axisX);
    m_series2->attachAxis(m_axisY);
    m_axisX->setTickCount(11);
    //m_axisY->setTickCount(6);
    m_axisX->setRange(0, 10);//设置x坐标轴的范围
    m_axisY->setRange(0, 500);//设置y坐标轴的范围

    m_timer.start();
}

Chart::~Chart()
{

}

void Chart::handleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();//设置坐标轴每次回滚的距离,取整数
    //qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();//x每次移动的距离
    //qDebug()<< plotArea().width()<<m_axisX->max()<<m_axisX->min()<< m_axisX->tickCount();
    m_x += 1;
    m_y = infectionNumber;/*QRandomGenerator::global()->bounded(5) - 2.5;*/
    m_y2 = healthNumber;
    m_series->append(m_x, m_y);
    m_series2->append(m_x, m_y2);
    //设置回滚，让线条变化处于中心位置
    if(m_x>=5)
        scroll(x, 0);
    //暂停条件
    if (m_x >= 300)
        m_timer.stop();
}

