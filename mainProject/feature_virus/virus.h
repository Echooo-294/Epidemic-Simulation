#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
public:
    Virus(double infectionP1=0.5,double infectionP2=0.8,\
          double socialEffect=1,double healthEffect=1,\
          double growthRate1=0.03,double growthRate2=0.05,double growthRate3=0.08,\
          double boundary1=0.3,double boundary2=0.72,double R0=3);
    double getInfectionP1() const;
    double getInfectionP2() const;
    double getGrowthRate1() const;
    double getGrowthRate2() const;
    double getGrowthRate3() const;
    double getBoundary1() const;
    double getBoundary2() const;

    double getHealthkEffect() const;
    void setHealthEffect(double value);
    double getR0() const;

    double getSocialEffect() const;
    void setSocialEffect(double value);
    void setR0(double value);



private:
    double infectionP1;//潜伏期感染概率
    double infectionP2;//出症状感染概率
    double socialEffect;//管控社交导致的感染概率
    double healthEffect;//政策影响的感染概率因子（口罩）
    double growthRate1;//潜伏期病毒增长率
    double growthRate2;//出症状病毒增长率
    double growthRate3;//重症病毒增长率
    double boundary1;//潜伏期的界限
    double boundary2;//重症界限
    double R0;//传染指数，每位感染者的传染人数上限
};

#endif // VIRUS_H
