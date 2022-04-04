/*
 * @Description: 完全开放政策模拟
 * @Author: Echooo
 * @Date: 2022-03-21
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-03-21
 */
#include<feature_resident/resident.h>
#include<feature_virus/virus.h>
#include<feature_timeAndStatistic/statistic.h>
#include<mapqgraphics.h>

/*
 * 使用前提：政策选择为完全开放
 * 参数：
 * 使用时间和空间：
 */
void MapQGraphics::fullyOpen()
{
    initPeople();//初始化人群
    initIncubation();//初始化感染潜伏者
//    //分组类并行，分三十趟，100个先移动，再感染或者其他，重复
//     QTimer *timer1=new QTimer();//初始化计时器
//     connect(timer1,timerout(),this,simulation1());//每500ms全部人要做的
//     timer1->start(500);
//     QTimer *timer2=new QTimer(parent);
//     connect(timer2,timerout(),);//每24h更新统计结果
//     timer2->start(6000);

}
//每500ms全部人要做的
void MapQGraphics::simulation1()
{
    //分组？
    //随机移动
    //感染者感染
    //病毒密度更新
    //是否进入医院
    //治疗

}