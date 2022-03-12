#include "virus.h"

Virus::Virus()
{

}

int Virus::getInfectivity() const
{
    return Infectivity;
}

double Virus::getOpenInfection() const
{
    return OpenInfection;
}

double Virus::getCloseInfection() const
{
    return CloseInfection;
}

int Virus::getInfectionDistance() const
{
    return InfectionDistance;
}

double Virus::getGrowthRate1() const
{
    return GrowthRate1;
}

double Virus::getGrowthRate2() const
{
    return GrowthRate2;
}

double Virus::getCureEffectiveness() const
{
    return CureEffectiveness;
}

double Virus::getMaskEffectiveness() const
{
    return MaskEffectiveness;
}
