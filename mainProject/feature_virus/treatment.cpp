/*
 * @Description: 治疗
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-17
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>

void Resident::treatment()
{
    const double recoveryRate=0.08;//治疗速率
    const double successRate=0.9*immunity;//治疗有效率
    if (randDouble()<successRate)
        virusDensity-=recoveryRate*immunity;
    if(virusDensity<=0)
    {
        virusDensity=0;
        immunity+=3;//免疫力+3
        setData(1,"heal");//设置标志痊愈
        goHome();//出院回家
    }
}
