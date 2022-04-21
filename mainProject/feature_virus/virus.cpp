#include "virus.h"

Virus::Virus(double infectionP1,double infectionP2,double openInfectionP,double closeInfectionP,\
             double growthRate1,double growthRate2,\
             double policyEffect,double boundary1,double boundary2):\
    infectionP1(infectionP1),infectionP2(infectionP2),\
    openInfectionP(openInfectionP),closeInfectionP(closeInfectionP),\
    growthRate1(growthRate1),growthRate2(growthRate2),\
    policyEffect(policyEffect),boundary1(boundary1),boundary2(boundary2)
{

}

double Virus::getopenInfectionP() const
{
    return openInfectionP;
}

double Virus::getcloseInfectionP() const
{
    return closeInfectionP;
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

double Virus::getmaskEffect() const
{
    return policyEffect;
}

double Virus::getBoundary1() const
{
    return boundary1;
}

double Virus::getBoundary2() const
{
    return boundary2;
}

double Virus::getPolicyEffect() const
{
    return policyEffect;
}

void Virus::setPolicyEffect(double value)
{
    policyEffect = value;
}

double Virus::getInfectionP1() const
{
    return infectionP1;
}

double Virus::getInfectionP2() const
{
    return infectionP2;
}

double Virus::getPoliceEffect() const
{
    return policyEffect;
}

void Virus::setPoliceEffect(double value)
{
    policyEffect = value;
}
