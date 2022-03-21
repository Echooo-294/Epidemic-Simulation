/*
 * @Description: 主函数
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
#include "widget.h"
#include<feature_virus/virus.h>
#include <QApplication>
//初始参数（全局变量）
int Population=3000;//初始总人数
int InitInfection=1;//初始感染人数
const double StartTime=6.0;//起始时间
const double UpdateTime=0.5;//更新间隔时间
int Policy=0;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
int Day=0;//天数
double Time=StartTime;//时间

int main(int argc, char *argv[])
{
    srand(time(NULL));//用于判断概率所需的随机数
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
