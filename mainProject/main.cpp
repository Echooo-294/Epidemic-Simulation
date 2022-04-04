/*
 * @Description: 主函数
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-26
 */
#include "widget.h"
#include<feature_virus/virus.h>
#include<feature_space/space.h>
#include <QApplication>
#include "ctime"
#include "cstdlib"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>


int main(int argc, char *argv[])
{
    srand(time(NULL));//用于判断概率所需的随机数
    QApplication a(argc, argv);
    Widget w;
    w.show();  

    return a.exec();
}
