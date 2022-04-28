/*
 * @Description: 图表类的声明
 * @Author: 巾可
 * @Date: 2022-04-24
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-04-25
 */
#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart: public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0); 
    QTimer m_timer;//动态图表的定时器
    virtual ~Chart();
public slots:
    void handleTimeout();
private:
    QSplineSeries *m_series;//可以理解为构成曲线的一系列的点,此处为感染人数
    QSplineSeries *m_series2;//可以理解为构成曲线的一系列的点,此处为健康人数
    QSplineSeries *m_series3;//可以理解为构成曲线的一系列的点,此处为死亡人数
    QStringList m_titles;
    QValueAxis *m_axisX;//x轴
    QValueAxis *m_axisY;//y轴
    qreal m_step;
    qreal m_x;//点的x坐标
    qreal m_y;//感染人数点的y坐标
    qreal m_y2;//健康人数点的y坐标
    qreal m_y3;//死亡人数点的y坐标
};


#endif
