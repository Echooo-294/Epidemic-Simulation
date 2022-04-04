#include "statistic.h"

//初始参数定义
int population=3000;//初始总人数
int initInfection=1;//初始感染人数
double updateTime=0.5;//更新间隔时间
int policy=0;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
int day=0;//天数
double showTime=6.0;//时间
Virus v(3,0.6,0.9,4,0.03,0.05,0.9,0.8,0.3,0.75);

//统计量

