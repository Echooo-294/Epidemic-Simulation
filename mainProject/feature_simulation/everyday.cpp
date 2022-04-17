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
    qDebug()<<"dayout";
    for(int i=0;i<livingNumber;i++)
    {
        people[i].virusGrowth();//病毒自然增长
        people[i].treatment();//治疗
        people[i].updateHealthStatus();//更新状态
    }
    showStatistic();//展示数据
}