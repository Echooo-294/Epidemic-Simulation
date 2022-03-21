#include "virus.h"

Virus::Virus(int a,double b,double c,int d,double e,double f,double g,double h,double i,double j):\
    infectivity(a),openInfection(b),closeInfection(c),infectionDistance(d),\
    growthRate1(e),growthRate2(f),cureEffectiveness(g),maskEffectiveness(h),\
    boundary1(i),boundary2(j)
{

}

int Virus::getinfectivity() const
{
    return infectivity;
}

double Virus::getopenInfection() const
{
    return openInfection;
}

double Virus::getcloseInfection() const
{
    return closeInfection;
}

int Virus::getinfectionDistance() const
{
    return infectionDistance;
}

double Virus::getgrowthRate1() const
{
    return growthRate1;
}

double Virus::getgrowthRate2() const
{
    return growthRate2;
}

double Virus::getcureEffectiveness() const
{
    return cureEffectiveness;
}

double Virus::getmaskEffectiveness() const
{
    return maskEffectiveness;
}

double Virus::getBoundary1() const
{
    return boundary1;
}

double Virus::getBoundary2() const
{
    return boundary2;
}
