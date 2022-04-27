#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QComboBox>
#include <QMessageBox>
#include "mainwindow.h"
#include <feature_timeAndStatistic/statistic.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //总人数初始化
    QLabel *initpoplab;
    QLabel *initinflab;
    QLabel *initpollab;
    QLineEdit *initpopline;
    QLineEdit *initinfline;
    QComboBox *initpolBox;

private slots:
    void on_startBtn_clicked();//确定按钮点击
private:
    Ui::Widget *ui;

    MainWindow *mainwin = NULL;
};
#endif // WIDGET_H
