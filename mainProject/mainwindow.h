/*
 * @Description: 主界面
 * @Date: 2022-04-04
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-04-04
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <feature_space/space.h>
#include <feature_timeAndStatistic/statistic.h>
#include "chart.h"
#include <QtCharts/QChartView>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    Chart *chart;//图表元素
    void reset();
    void mapInit();
    void everyday();
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    //状态栏
    QLabel *curlocLab;
    QLabel *curbuiLab;
    //地图的视图
    QGraphicsScene *scene=NULL;
    QTimer *timer;//模拟每隔一定时间的更新

public slots:
    //获得鼠标移动和点击的槽函数
    void get_Mouse_Point(QPoint point);
    void get_Mouse_Point_Press(QPoint point);
    //一些控制按钮的槽函数
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_lineEdit_9_textChanged(const QString &arg1);
    void on_actexit_triggered();
signals:
    void emitExit();//发射退出信号，退回开始页面
};

#endif // MAINWINDOW_H
