//地图，专门用来画图，便于安放建筑和人


#ifndef MAPWIDG_H
#define MAPWIDG_H

#include <QWidget>

namespace Ui {
class MapWidg;
}

class MapWidg : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidg(QWidget *parent = nullptr);
    ~MapWidg();

private:
    Ui::MapWidg *ui;
    void paintEvent(QPaintEvent *event) override;//重写painterEvent事件，在QWidget类中添加图
    void mouseMoveEvent(QMouseEvent *event) override;//重写mouseMoveEvent，获得鼠标所在坐标

signals:
    void send_Mouse_Point(int x,int y);
};

#endif // MAPWIDG_H
