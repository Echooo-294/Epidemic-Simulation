#ifndef VIRUS_H
#define VIRUS_H
#include<QObject>

class Virus:public QObject
{
public:
    Virus();
    int getInfectivity() const;
    double getOpenInfection() const;
    double getCloseInfection() const;
    int getInfectionDistance() const;
    double getGrowthRate1() const;
    double getGrowthRate2() const;
    double getCureEffectiveness() const;
    double getMaskEffectiveness() const;

private:
    int Infectivity;//传染人数上限
    double OpenInfection,CloseInfection;//感染概率
    int InfectionDistance;//可感染范围
    double GrowthRate1;//潜伏期病毒增长率
    double GrowthRate2;//出症状病毒增长率
    double CureEffectiveness;//治疗有效性
    double MaskEffectiveness;//口罩有效性
};

#endif // VIRUS_H
