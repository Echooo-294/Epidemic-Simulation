#include "virus.h"

Virus::Virus(double infectionP1,double infectionP2,double socialEffect,\
             double growthRate1,double growthRate2,double policyEffect,\
             double boundary1,double boundary2, double R0):\
    infectionP1(infectionP1),infectionP2(infectionP2),\
    socialEffect(socialEffect),\
    growthRate1(growthRate1),growthRate2(growthRate2),\
    maskEffect(policyEffect),boundary1(boundary1),boundary2(boundary2),R0(R0)
{
}

double Virus::getgrowthRate1() const
{
    return growthRate1;
}

double Virus::getgrowthRate2() const
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

double Virus::getMaskEffect() const
{
    return maskEffect;
}

void Virus::setMaskEffect(double value)
{
    maskEffect = value;
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

double Virus::getInfectionP1() const
{
    return infectionP1;
}

double Virus::getInfectionP2() const
{
    return infectionP2;
}
