#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
public:
    Virus(double infectionP1=0.5,double infectionP2=0.8,\
          double socialEffect=1,\
          double growthRate1=0.03,double growthRate2=0.05,\
          double maskEffect=1,double boundary1=0.3,double boundary2=0.75,double R0=3);
    double getInfectionP1() const;
    double getInfectionP2() const;
    double getgrowthRate1() const;
    double getgrowthRate2() const;
    double getBoundary1() const;
    double getBoundary2() const;
    double getMaskEffect() const;
    void setMaskEffect(double value);
    double getR0() const;

    double getSocialEffect() const;
    void setSocialEffect(double value);
    void setR0(double value);

private:
    double infectionP1;//潜伏期感染概率，默认=0.5
    double infectionP2;//出症状感染概率，默认=0.8
    double socialEffect;//管控社交导致的感染概率，对应1，0.8，0.5，0.3
    double growthRate1;//潜伏期病毒增长率，默认=0.03
    double growthRate2;//出症状病毒增长率，默认=0.05
    double maskEffect;//政策影响的感染概率因子（口罩），对应1，0.9，0.7，0.6
    double boundary1;//潜伏期的界限，默认=0.3
    double boundary2;//重症界限，默认=0.75
    double R0;//传染指数，感染人数上限，默认=3
};

#endif // VIRUS_H
