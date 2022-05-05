/*
 * @Description: 每日的更新
 * @Author: Echooo
 * @Date: 2022-04-17
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-05-03
 */
#include<feature_timeAndStatistic/statistic.h>
#include<feature_resident/resident.h>
#include"mapqgraphics.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::everyday()
{
    ui->lineEdit->setText(QString::number(day));
    ui->lineEdit_2->setText(QString::number(initPopulation-deadNumber));
    ui->lineEdit_3->setText(QString::number(healthNumber));
    ui->lineEdit_4->setText(QString::number(infectionNumber));
    ui->lineEdit_5->setText(QString::number(isolationNumber));
    ui->lineEdit_6->setText(QString::number(immunityNumber));
    ui->lineEdit_7->setText(QString::number(seriousNumber));
    ui->lineEdit_8->setText(QString::number(deadNumber));
    ui->timeEdit->setTime(QTime(showTime,0));
}
void MapQGraphics::everyday()
{
    int healthStatus=0;
    int activityStatus=0;
    int i=0;
    int isolateday=0;
    for(;i<initPopulation;i++)
    {
        healthStatus=people[i].getHealthStatus();
        activityStatus=people[i].getActivityStatus();

        if(activityStatus>=2)
            people[i].isolateDayInc();//隔离天数+1
        isolateday=people[i].getIsolateDay();

        //病毒自然增长
        if(healthStatus!=0&&healthStatus!=4)//如果非健康非死亡
            people[i].virusGrowth();

        //如果在治疗中
        if(activityStatus==4&&people[i].getHealthStatus()!=0)
            people[i].treatment(buildings[5]);

        healthStatus=people[i].getHealthStatus();//更新由于病毒增长和治疗带来的变化

        //释放满足条件的独立隔离、居家隔离人员
        if(activityStatus==2&&healthStatus==0&&isolateday>7)
        {
            //把隔离区隔离时间大于7天的健康人释放
            people[i].goHome();
            buildings[6]->restRoomInc();
        }
        else if(activityStatus==3&&healthStatus<2&&isolateday>3)
        {
            //释放无症状、健康的居家隔离超过三天的人
            people[i].setActivityStatus(0);
            people[i].setIsolateDay(0);
        }

    }
    int j=0;
    //政策2、3、4疫苗接种，有每日接种上限，取决于政策
    if(policy>=2&&immunityNumber<initPopulation)
        for(i=0;i<policy*100&&immunityNumber<=initPopulation;i++)
        {
            j=rand()%initPopulation;
            if(people[j].getVaccine()==0)//由于随机导致的重复，接种速率日渐降低，这也符合实际
            {
                people[j].setVaccine();
                immunityNumber++;
            }
        }
    //政策3、4设置居家隔离，有每日新居家隔离人数上限，取决于政策
    if(policy>=3)
         for(i=0;i<policy*50;i++)
         {
             j=rand()%initPopulation;
             if(people[j].getActivityStatus()<=1)//由于随机导致的重复，居家隔离速率日渐降低
                 people[j].setActivityStatus(3);//设为居家隔离
         }

}

