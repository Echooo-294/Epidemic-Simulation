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
    int sum1=0;
    int sum2=0;
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
            people[i].treatment(buildings[5]);//治疗
        //隔离相关
        if(activityStatus==3&&healthStatus<2&&isolateday>3)//释放无症状、健康的居家隔离超过三天的人
        {
            people[i].setActivityStatus(0);
            people[i].setIsolateDay(0);
        }
        if(activityStatus==2&&people[i].getHealthStatus()==0&&isolateday>7)//把隔离区隔离时间大于7天的健康人释放
        {
            people[i].goHome();
            buildings[6]->restRoomInc();
        }
        if(policy>=2&&people[i].getVaccine()==0&&sum1<=policy*75)//有上限
        {
            if(randDouble()<0.4)
            {
                people[i].setVaccine();
                sum1++;
                immunityNumber++;
            }
        }
        if(policy>=3&&activityStatus<=1&&sum2<=policy*40)//如果有管控政策，有上限
            if(randDouble()>v.getSocialEffect()*1.8)//适度管控为0.5，严格管控为0.3
            {
                people[i].setActivityStatus(3);//设为居家隔离
                sum2++;
            }
    }
}

