/*
 * @Description: 每日的更新
 * @Author: Echooo
 * @Date: 2022-04-17
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-17
 */
#include<feature_timeAndStatistic/statistic.h>
#include<feature_resident/resident.h>
#include"mapqgraphics.h"
void MapQGraphics::everyday()
{
    int healthStatus=0;
    for(int i=0;i<initPopulation;i++)
    {
        healthStatus=people[i].getHealthStatus();
        if(healthStatus!=0&&healthStatus!=4)//如果非健康非死亡
        {
            people[i].virusGrowth();//病毒自然增长
        }
        if(people[i].getActivityStatus()==4)//如果在治疗中
        {
            people[i].treatment();//治疗
        }
        //不需要更新状态，每隔一定时间的模拟都会更新状态
    }
    showStatistic();//展示数据
}