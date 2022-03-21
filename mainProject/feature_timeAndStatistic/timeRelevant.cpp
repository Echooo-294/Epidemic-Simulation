/*
 * @Description: 时间相关
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
extern double StartTime;//起始时间
extern double UpdateTime;//更新间隔时间
extern int Day;
extern double Time;//时间

double getrand()//用于判断概率所需的随机数，种子在主函数中设置
{
    const int n=99;
    const double p = rand()%(n+1)/(double)(n+1);
    return p;
}
double UpdateTime()//更新当前时间和日期
{

}