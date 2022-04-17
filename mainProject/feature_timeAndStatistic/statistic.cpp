/*
 * @Description: 初始参数、统计量、统计结果相关函数的定义
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-12
 */
#include "statistic.h"
#include<feature_resident/resident.h>

//病毒自然增长以及治疗 需要根据更新时间修改!!!!!!!
//或者初始赋值都是每天的变化，通过数学公式计算
//或者让这两者直接一天一用，而不是每多少时间使用

//初始参数定义
int initPopulation=400;//初始总人数
int initInfection=1;//初始感染人数
double updateTime=2;//更新间隔时间
int policy=0;//政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
Virus v(3,0.6,0.9,4,0.03,0.05,0.9,0.8,0.3,0.75);
int buildingNumber=7;//建筑数量

//统计量
int livingNumber=initPopulation;//存活人数
int healthNumber=0;//正常人数
int infectionNumber=0;//总感染人数
int isolationNumber=0;//隔离人数，也算在感染，治疗也算隔离
int seriousNumber=0;//重症人数，也算在感染
int deadNumber=0;//死亡人数，加上总人数应该=initPopulation
int immunityNumber=0;//疫苗接种人数
int day=0;//天数
double showTime=6.0;//时间

void showStatistic()
{
    qDebug()<<"模拟天数："<<day;
//    qDebug()<<"正常人数："<<healthNumber;
    qDebug()<<"感染人数："<<infectionNumber;
//    qDebug()<<"隔离人数："<<isolationNumber;
//    qDebug()<<"重症人数："<<seriousNumber;
//    qDebug()<<"死亡人数："<<deadNumber;
//    qDebug()<<"疫苗接种人数："<<immunityNumber;
}
