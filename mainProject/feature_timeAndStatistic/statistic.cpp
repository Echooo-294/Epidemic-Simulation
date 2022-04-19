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
int initPopulation=400;//初始总人数
int initInfection=1;//初始感染人数
double updateTime=2;//更新间隔时间
int policy=0;//政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
Virus v(0.6,0.9,4,0.03,0.05,0.9,0.8,0.3,0.75);
int buildingNumber=7;//建筑数量

//统计量
int livingNumber=initPopulation;//存活人数
int healthNumber=initPopulation;//正常人数
int infectionNumber=initInfection;//总感染人数，包括隔离和重症，被感染后自我状态更新时+1
int isolationNumber=0;//隔离人数，治疗也算隔离，每有一人被隔离或进入医院，则+1
int seriousNumber=0;//重症人数，状态更新时，如果变为重症则+1
int deadNumber=0;//死亡人数，加上总人数应该=initPopulation
int immunityNumber=0;//疫苗接种人数
int day=0;//天数
double showTime=6.0;//时间，起始为6点

void showStatistic()
{
    qDebug()<<"模拟天数："<<day;
//    qDebug()<<"正常人数："<<healthNumber;
//    qDebug()<<"感染人数："<<infectionNumber;
//    qDebug()<<"隔离人数："<<isolationNumber;
//    qDebug()<<"重症人数："<<seriousNumber;
//    qDebug()<<"死亡人数："<<deadNumber;
//    qDebug()<<"疫苗接种人数："<<immunityNumber;
}
