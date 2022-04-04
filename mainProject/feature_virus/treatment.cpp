/*
 * @Description: 治疗
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-04
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
/*
 * 用于判断是否进入医院，轻症患者有一半的概率进入医院，全部重症患者进入医院
 * 使用前提：病毒密度大于0且小于1，健康状态为非健康和存活
 * 参数：居民对象（或数组）和病毒对象
 * 使用时间和空间：每日更新（或每多少时间），需要处于医院
 */
void judgeIntoHos()
{
    const double p=getran();

}
/*
 * 用于治疗
 * 使用前提：病毒密度大于0且小于1，健康状态为非健康和存活，活动状态处于治疗中
 * 参数：居民对象（或数组）和病毒对象
 * 使用时间和空间：每日更新（或每多少时间），需要处于医院
 */
void treatment(Resident &people)
{
    if(people.getHealthStatus()==0||people.getHealthStatus()==4\
            ||people.getActivityStatus()!=4)//健康状态为非健康和存活，活动状态处于治疗中
        return;
    const double density=people.getVirusDensity();
    const double recoveryRate=0.075;//治疗速率
    const double successRate=0.9;//治疗有效率
    const double p=getrand();
    if (p>0&&p<=successRate)
        people.setVirusDensity(density-recoveryRate);
}