/*
 * @Description: 初始参数、统计量、统计结果相关函数的定义
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-12
 */
#include "statistic.h"
#include<feature_resident/resident.h>

//初始参数定义
int initPopulation;//初始总人数
int initInfection;//初始感染人数
double updateTime=2;//更新间隔时间
int policy;//政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
Virus v;
int buildingNumber=12;//建筑数量

//统计量初始值
int healthNumber;//正常人数
int infectionNumber;//总感染人数，包括隔离、无症状和重症
int isolationNumber;//隔离人数，治疗也算隔离，每有一人被隔离或进入医院，则+1
int seriousNumber;//重症人数
int deadNumber;//死亡人数
int immunityNumber;//疫苗接种人数
int day;//天数
double showTime;//时间，起始为0点

void showStatistic()
{   
    qDebug()<<"模拟天数："<<day;
    qDebug()<<"存活人数："<<initPopulation-deadNumber;
    qDebug()<<"正常人数："<<healthNumber;
    qDebug()<<"感染者："<<infectionNumber;
    qDebug()<<"隔离人数："<<isolationNumber;
    qDebug()<<"重症人数："<<seriousNumber;
    qDebug()<<"死亡人数："<<deadNumber;
    qDebug()<<"疫苗接种人数："<<immunityNumber;
}
