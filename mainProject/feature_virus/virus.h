#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
public:
    Virus(double infectionP1,double infectionP2,double openInfectionP,double closeInfectionP,\
          double growthRate1,double growthRate2,double policyEffect,\
          double boundary1,double boundary2);
    double getInfectionP1() const;
    double getInfectionP2() const;
    double getopenInfectionP() const;
    double getcloseInfectionP() const;
    double getgrowthRate1() const;
    double getgrowthRate2() const;
    double getBoundary1() const;
    double getBoundary2() const;
    double getPolicyEffect() const;
    void setPolicyEffect(double value);
private:
    double infectionP1;//潜伏期感染概率
    double infectionP2;//出症状感染概率
    double openInfectionP;//开放空间感染概率
    double closeInfectionP;//密闭空间感染概率
    double growthRate1;//潜伏期病毒增长率
    double growthRate2;//出症状病毒增长率
    double policyEffect;//政策影响（口罩、管控）
    double boundary1;//潜伏期的界限
    double boundary2;//重症界限
};

#endif // VIRUS_H
