#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionexit_triggered();

private:
    Ui::MainWindow *ui;
    //状态栏上的显示
    QLabel *curlocLab;
    QLabel *curbuiLab;
};

#endif // MAINWINDOW_H
