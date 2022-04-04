/*
 * @Description: 病毒自然增长
 * @Author: Echooo
 * @Date: 2022-03-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-15
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
/*
 * 使用前提：病毒密度大于0且小于1，健康状态为非健康和存活
 * 参数：居民对象（或数组）和病毒对象
 * 使用时间和空间：每日更新（或每多少时间），无空间限制
 */
void virusGrowth(Resident &people)
{
    if(people.getHealthStatus()==0||people.getHealthStatus()==4)//健康状态为非健康和存活
        return;
    const double density=people.getVirusDensity();
    const double growthRate1=v.getgrowthRate1();//潜伏期自然增长率
    const double growthRate2=v.getgrowthRate2();//出症状后自然增长率
    const double boundary1=v.getBoundary1();//潜伏与出症状的密度界限
    if(density>=0&&density<boundary1)
        people.setVirusDensity(density+growthRate1);//潜伏期自然增长
    else if(density<1&&density>=boundary1)
        people.setVirusDensity(density+growthRate2);//出症状后自然增长
}
