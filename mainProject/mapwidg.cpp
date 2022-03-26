#include "mapwidg.h"
#include "ui_mapwidg.h"
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
MapWidg::MapWidg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidg)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::gray));
    setAutoFillBackground(true);
}

MapWidg::~MapWidg()
{
    delete ui;
}

void MapWidg::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    //
}

void MapWidg::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(true);//默认追踪鼠标位置
    int x=event->x();
    int y=event->y();
    emit send_Mouse_Point(x,y);
    QWidget::mouseMoveEvent(event);
}

