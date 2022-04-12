#include "statistic.h"
#include<feature_resident/resident.h>
//初始参数定义
int initPopulation=3000;//初始总人数
int initInfection=1;//初始感染人数
double updateTime=2;//更新间隔时间
int policy=0;//政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
Virus v(3,0.6,0.9,4,0.03,0.05,0.9,0.8,0.3,0.75);

//统计量
int population=0;//总人数
int infectionNumber=0;//总感染人数
int isolationNumber=0;//隔离人数
int seriousNumber=0;//重症人数
int deadNumber=0;//死亡人数
int immunityNumber=0;//疫苗接种人数
int day=0;//天数
double showTime=7.0;//时间

void showStatistic()
{
    qDebug()<<"模拟天数："<<day;
//    qDebug()<<"正常人数："<<population-infectionNumber;
//    qDebug()<<"感染人数："<<infectionNumber;
//    qDebug()<<"隔离人数："<<isolationNumber;
//    qDebug()<<"重症人数："<<seriousNumber;
//    qDebug()<<"死亡人数："<<deadNumber;
//    qDebug()<<"疫苗接种人数："<<immunityNumber;
}
