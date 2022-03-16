/*
 * @Description: 病毒自然增长
 * @Author: Echooo
 * @Date: 2022-03-12
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-15
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
/*
 * 使用前提：病毒密度大于0且小于1
 * 参数：居民对象（或数组）和病毒对象
 * 使用时间和空间：每日更新（或每多少时间），无空间限制
 */
void virusGrowth(Resident &people,const Virus &v)
{
    double density=people.getVirusDensity();
    double growthRate1=v.getgrowthRate1();//0.03
    double growthRate2=v.getgrowthRate2();//0.05
    double boundary1=0.3;//潜伏与出症状的密度界限
    if(density>0&&density<boundary1)
        people.setVirusDensity(density+growthRate1);//潜伏期自然增长
    else if(density<1&&density>=boundary1)
        people.setVirusDensity(density+growthRate2);//出症状后自然增长
}
