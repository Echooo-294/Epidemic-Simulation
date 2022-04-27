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
#include"mainwindow.h"
#include "ui_mainwindow.h"
void MapQGraphics::everyday()
{
    int healthStatus=0;
    int i=0;
    for(;i<initPopulation;i++)
    {
        healthStatus=people[i].getHealthStatus();
        if(healthStatus!=0&&healthStatus!=4)//如果非健康非死亡
            people[i].virusGrowth();//病毒自然增长
        if(people[i].getActivityStatus()==4)//如果在治疗中
        {
            people[i].treatment(buildings[5]);//治疗
        }
        //不需要更新状态，每隔一定时间的模拟都会更新状态

        if(people[i].getActivityStatus()==2&&people[i].getHealthStatus()==0)
        {
            if(people[i].getIsolateDay()>=14)//把隔离区隔离时间大于14天的健康人移出来
                people[i].goHome();
            else
                people[i].isolateDayInc();//隔离天数+1
        }
    }
    showStatistic();//展示数据
}
void MainWindow::everyday()
{
    ui->lineEdit->setText(QString::number(day));
    ui->lineEdit_2->setText(QString::number(initPopulation-deadNumber));
    ui->lineEdit_3->setText(QString::number(healthNumber));
    ui->lineEdit_4->setText(QString::number(infectionNumber));
    ui->lineEdit_5->setText(QString::number(isolationNumber));
    ui->lineEdit_6->setText(QString::number(nosymNumber));
    ui->lineEdit_7->setText(QString::number(seriousNumber));
    ui->lineEdit_8->setText(QString::number(deadNumber));
    ui->timeEdit->setTime(QTime(showTime,0));
}
