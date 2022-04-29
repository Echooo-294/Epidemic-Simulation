#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QComboBox>
#include <QMessageBox>
#include "mainwindow.h"
#include "contrast.h"
#include <feature_timeAndStatistic/statistic.h>
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QLabel *initpoplab;
    QLabel *initinflab;
    QLabel *initpollab;
    QLineEdit *initpopline;
    QLineEdit *initinfline;
    QComboBox *initpolBox;
    void record();
private slots:
    void on_startBtn_clicked();//确定按钮点击
signals:
    void give_init(QVector<int>);
private:
    Ui::Widget *ui;
    QVector<int> vec;
    MainWindow *mainwin = NULL;
    Contrast *cont=NULL;
};
#endif // WIDGET_H
