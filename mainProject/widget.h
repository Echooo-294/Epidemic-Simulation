#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startBtn_clicked();

private:
    Ui::Widget *ui;

    MainWindow *mainwin = NULL;
};
#endif // WIDGET_H
