/*
 * @Description: 时间相关
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
#include "cstdlib"


double getrand()//用于判断概率所需的随机数，种子在主函数中设置
{
    const int n=99;
    const double p = rand()%(n+1)/(double)(n+1);
    return p;
}
void updateTime()//更新显示时间
{

}