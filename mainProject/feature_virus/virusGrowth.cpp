/*
 * @Description: 病毒自然增长
 * @Author: Echooo
 * @Date: 2022-03-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-05-04
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
void Resident::virusGrowth()
{
    //在外层使用前判断非健康非死亡
    const double boundary1=v.getBoundary1();//潜伏与出症状的密度界限
    const double boundary2=v.getBoundary2();//出症状与重症的密度界限
    double k=0.6;
    if(healthStatus==2)
        k=0.75;
    else if(healthStatus==3)
        k=0.9;
    const double P=(9/(10*immunity))*k;//病毒增长的概率和免疫力相关，也和病毒密度相关
    double p=randDouble();
    if(p<P)
    {
        if(virusDensity>=0&&virusDensity<boundary1)
            virusDensity+=v.getGrowthRate1();//潜伏期自然增长
        else if(virusDensity>=boundary1&&virusDensity<boundary2)
            virusDensity+=v.getGrowthRate2();//出症状后自然增长
        else if(virusDensity>=boundary2&&virusDensity<1)
            virusDensity+=v.getGrowthRate3();//重症后自然增长
    }
    //每次病毒自然增长，有概率增加可传染人数
    if(p<0.1)
        infNumber-=2;
    else if(p<0.4)
        infNumber--;
}
