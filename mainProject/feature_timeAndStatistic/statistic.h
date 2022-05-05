/*
 * @Description: 初始参数、统计量、随机数和定时器头文件等声明
 * @Author: Echooo
 * @Date: 2022-03-03
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-05-05
 */
#ifndef STATISTIC_H
#define STATISTIC_H
#include<QTimer>
#include<feature_virus/virus.h>
#include<QDebug>
#include<QVector>
#include <cmath>

//初始参数
extern int initPopulation;//初始总人数
extern int initInfection;//初始感染人数
extern double updateTime;//更新间隔时间
extern int policy;//政策
extern Virus v;
extern int buildingNumber;
//统计量
extern int healthNumber;//正常人数
extern int infectionNumber;//总感染人数
extern int isolationNumber;//隔离人数
extern int seriousNumber;//重症人数
extern int deadNumber;//死亡人数
extern int immunityNumber;//疫苗接种人数
extern int day;//天数
extern double showTime;//时间
//rand() 返回任意正整数
double randDouble();//返回0-1double
void updateShowTime();//更新展示的时间


#endif // STATISTIC_H
