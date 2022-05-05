/*
 * @Description: 治疗
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-05-03
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>

void Resident::treatment(Space **h)
{
    //治疗速率，ln1.6=0.47，ln2=0.69，ln3=1.09，ln8=2.07
    const double recoveryRate=\
            log(exp(immunity+1))*0.12+randDouble()*0.01+virusDensity*0.03;
    //治疗有效率
    const double successRate=0.9;
    if (randDouble()<successRate)
        virusDensity-=recoveryRate;
    if(virusDensity<=0)
    {
        virusDensity=0;
        immunity+=5;//免疫力+5
        setData(1,"heal");//设置标志痊愈
        goIsolate(h[6]);//出院回家
        isolationNumber--;
        h[5]->restRoomInc();//剩余床位+1
        //数量变化在update中进行
//        infectionNumber--;//感染-1
//        healthNumber++;//健康+1
    }
}
