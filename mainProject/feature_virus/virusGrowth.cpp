/*
 * @Description: 病毒自然增长
 * @Author: Echooo
 * @Date: 2022-03-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-21
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
/*
 * 使用前提：病毒密度大于0且小于1，健康状态为非健康和存活
 * 使用时间和空间：每日更新（或每多少时间），无空间限制
 */
void Resident::virusGrowth()
{
    //在外层使用前判断非健康非死亡
    const double boundary1=v.getBoundary1();//潜伏与出症状的密度界限
    double k=0.4;
    if(healthStatus==2)
        k=0.6;
    else if(healthStatus==3)
        k=0.8;
    const double P=(3/(4*immunity))*k;//病毒的增长概率和免疫力相关，也和病毒密度相关
    if(randDouble()<P)
    {
        if(virusDensity>=0&&virusDensity<boundary1)
            virusDensity+=v.getgrowthRate1();//潜伏期自然增长
        else if(virusDensity<1&&virusDensity>=boundary1)
            virusDensity+=v.getgrowthRate2();//出症状后自然增长
    }
}
