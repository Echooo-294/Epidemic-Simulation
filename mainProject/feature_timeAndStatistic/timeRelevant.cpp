/*
 * @Description: 时间相关
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
#include "cstdlib"
#include<feature_timeAndStatistic/statistic.h>
//产生随机数
int randInt()
{
    return rand();
}
double randDouble()//用于判断概率所需的随机数0-1，种子在主函数中设置
{
    const int n=99;
    const double p = rand()%(n+1)/(double)(n+1);
    return p;
}
void updateShowTime()//更新显示时间
{
    showTime+=updateTime;
    if(showTime>=24.0)
    {
        showTime=0;
        day++;
    }
}