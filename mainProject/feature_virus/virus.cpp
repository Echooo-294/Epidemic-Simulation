#include "virus.h"

Virus::Virus(double infectionP1,double infectionP2,double socialEffect,double healthEffect,\
             double growthRate1,double growthRate2,double growthRate3,\
             double boundary1,double boundary2, double R0):\
    infectionP1(infectionP1),infectionP2(infectionP2),\
    socialEffect(socialEffect),healthEffect(healthEffect),\
    growthRate1(growthRate1),growthRate2(growthRate2),growthRate3(growthRate3),\
    boundary1(boundary1),boundary2(boundary2),R0(R0)
{
}

double Virus::getGrowthRate1() const
{
    return growthRate1;
}

double Virus::getGrowthRate2() const
{
    return growthRate2;
}

double Virus::getBoundary1() const
{
    return boundary1;
}

double Virus::getBoundary2() const
{
    return boundary2;
}

double Virus::getHealthkEffect() const
{
    return healthEffect;
}

void Virus::setHealthEffect(double value)
{
    healthEffect = value;
}

double Virus::getR0() const
{
    return R0;
}

double Virus::getSocialEffect() const
{
    return socialEffect;
}

void Virus::setSocialEffect(double value)
{
    socialEffect = value;
}

void Virus::setR0(double value)
{
    R0 = value;
}

double Virus::getGrowthRate3() const
{
    return growthRate3;
}

double Virus::getInfectionP1() const
{
    return infectionP1;
}

double Virus::getInfectionP2() const
{
    return infectionP2;
}
