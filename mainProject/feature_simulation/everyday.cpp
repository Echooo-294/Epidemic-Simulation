/*
 * @Description: 每日的更新
 * @Author: Echooo
 * @Date: 2022-04-17
 * @Last Modified by: Echooo
 * @Last Modified time: 2022-04-28
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

    ui->lineEdit_7->setText(QString::number(seriousNumber));
    ui->lineEdit_8->setText(QString::number(deadNumber));
    ui->timeEdit->setTime(QTime(showTime,0));
}
void MapQGraphics::everyday()
{
    int healthStatus=0;
    int activityStatus=0;
    int i=0;
    int sum=0;
    for(;i<initPopulation;i++)
    {
        healthStatus=people[i].getHealthStatus();
        activityStatus=people[i].getActivityStatus();
        //病毒自然增长
        if(healthStatus!=0&&healthStatus!=4)//如果非健康非死亡
            people[i].virusGrowth();
        //如果在治疗中
        if(activityStatus==4&&people[i].getHealthStatus()!=0)
            people[i].treatment(buildings[5]);//治疗
        //隔离相关
        if(activityStatus==2&&people[i].getHealthStatus()==0)
        {
            if(people[i].getIsolateDay()>=7)//把隔离区隔离时间大于14天的健康人移出来
            {
                people[i].goHome();
                buildings[6]->restRoomInc();
            }
            else
                people[i].isolateDayInc();//隔离天数+1
        }
        if(policy>=2&&people[i].getVaccine()!=0&&sum<=100)//一天最多一百人接种
        {
            if(randDouble()<0.4)
            {
                people[i].setVaccine();
                sum++;
                immunityNumber++;
            }
        }
    }
}

