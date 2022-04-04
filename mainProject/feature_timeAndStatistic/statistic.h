/*
 * @Description: 初始参数、统计量、随机数和定时器头文件等声明
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-04
 */
#ifndef STATISTIC_H
#define STATISTIC_H

#include<QTimer>
#include<feature_virus/virus.h>
#include<QDebug>
#include<QVector>

//初始参数
extern int population;//初始总人数
extern int initInfection;//初始感染人数
extern double updateTime;//更新间隔时间
extern int policy;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
extern int day;//天数
extern double showTime;//时间
extern Virus v;

//统计量
double getrand();
//定时器


#endif // STATISTIC_H
