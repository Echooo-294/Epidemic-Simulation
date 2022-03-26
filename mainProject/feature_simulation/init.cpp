/*
 * @Description: 初始化
 * @Author: Echooo
 * @Date: 2022-03-26
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-26
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
//初始参数（全局变量）
int Population=3000;//初始总人数
int InitInfection=1;//初始感染人数
const double StartTime=6.0;//起始时间
const double UpdateTime=0.5;//更新间隔时间
int Policy=0;//防疫政策：0完全开放，1疫苗接种+不管控，2疫苗接种+适度管控，3疫苗接种+适度管控+零容忍
int Day=0;//天数
double Time=StartTime;//时间

//需要一个父控件，使Resident*继承他以便图形化
//需要限制初始位置
QVector<Resident*> initPeople()
{
    QVector<Resident*> allPeople;
    allPeople.reserve(Population);
    for(int i=0;i<Population;i++)
    {
        Resident* adult;
        allPeople.append(adult);
    }
    return allPeople;
}
QVector<Resident*> initIncubation(QVector<Resident*>& allPeople)
{
    QVector<Resident*> incubations;//感染潜伏
    incubations.reserve(InitInfection);
    QVector<Resident*>::iterator iter=allPeople.begin();
    for(int i=0;i<InitInfection;i++)//初始感染潜伏
    {
        (*iter)->setHealthStatus(1);
        incubations.append(*iter);
        iter++;
    }
    return incubations;
}
