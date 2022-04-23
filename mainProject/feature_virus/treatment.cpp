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
#include<mapqgraphics.h>
/*
 * 使用前提：病毒密度大于0且小于1，健康状态为非健康和存活，活动状态处于治疗中
 * 使用时间和空间：每日更新（或每多少时间），需要处于医院
 */
void Resident::treatment(int &restroom)
{
    const double recoveryRate=0.08;//治疗速率
    const double successRate=0.9*immunity;//治疗有效率
    if (randDouble()<successRate)
        virusDensity-=recoveryRate*immunity;
    if(virusDensity<=0)
    {
        virusDensity=0;
        immunity+=3;//免疫力+3
        goHome();//出院回家
        restroom=restroom+1;
        infectionNumber--;//感染-1
        healthNumber++;//健康+1
    }
}
