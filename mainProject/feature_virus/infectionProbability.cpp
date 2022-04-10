/*
 * @Description: 感染概率
 * @Author: Mars
 * @Date: 2022-03-21
 * @Last Modified by: Mars
 * @Last Modified time: 2022-04-4
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
/*
 * 参数：两个居民对象（带病毒者和被计算感染概率者）和病毒对象
 * 使用时间和空间：出现感染者后，对感染者周围4米范围内每一小时计算一次
 */

bool infectionP(Resident &people1,Resident &people2)//考虑距离 要加上两个居民对应图元
{
    //如果已治愈则无法感染

    //如果感染次数达到上限也返回0，不能感染
    if(people2.getHealthStatus()==0)//如果后者也是感染者，直接等于没被感染
    {
    double density=people1.getVirusDensity();//病毒密度
    double status=0;//病毒感染者是潜伏or出症状
    if(people1.getHealthStatus()==1)status=v.getgrowthRate1();
    else status=v.getgrowthRate2();
    double vaccine=1;//是否打疫苗
    if(people2.getVaccine()==1)
        vaccine=0.5;
    double mask=v.getmaskEffectiveness(); //是否做了防护措施 看政策 可能还要加参数
    double place=1; //所处空间的感染概率  感觉要在resident里加入判断人在什么地方的函数
    double p=density*status*vaccine*mask*place;
    //随机数判断是否感染
    double pp=getrand();
    if(pp<p)return 1;
    else return 0;
    }
    return 0;
}
