#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
public:
    Virus(int a,double b,double c,int d,double e,double f,double g,double h,double i,double j);
    int getinfectivity() const;
    double getopenInfection() const;
    double getcloseInfection() const;
    int getinfectionDistance() const;
    double getgrowthRate1() const;
    double getgrowthRate2() const;
    double getcureEffectiveness() const;
    double getmaskEffectiveness() const;
    double getBoundary1() const;
    double getBoundary2() const;
private:
    int infectivity;//传染人数上限
    double openInfection,closeInfection;//感染概率
    int infectionDistance;//可感染范围
    double growthRate1;//潜伏期病毒增长率
    double growthRate2;//出症状病毒增长率
    double cureEffectiveness;//治疗有效性
    double maskEffectiveness;//口罩有效性
    double boundary1;//潜伏期的界限
    double boundary2;//重症界限
};

#endif // VIRUS_H
