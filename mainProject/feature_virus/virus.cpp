#include "virus.h"

Virus::Virus()
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
