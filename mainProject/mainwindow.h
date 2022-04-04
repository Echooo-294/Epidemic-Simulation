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
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void mapInit();
    ~MainWindow();

private slots:
    void on_actionexit_triggered();

private:
    Ui::MainWindow *ui;
    //状态栏上的显示
    QLabel *curlocLab;
    QLabel *curbuiLab;
    //图的视图
    QGraphicsScene *scene=NULL;

private slots:
    void get_Mouse_Point(QPoint point);
    void get_Mouse_Point_Press(QPoint point);
};

#endif // MAINWINDOW_H
