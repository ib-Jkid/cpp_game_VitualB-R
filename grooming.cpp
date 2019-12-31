#include "grooming.h"

Grooming::Grooming()
{
    bathCost = 10.0;
    laundryCost = 20.0;
    washHandCost = 1.0;
    brushCost = 5.0;
}
void Grooming::gameCycle(double rate) {
    bathCost += (bathCost * rate);
    laundryCost += (laundryCost * rate);
    washHandCost += (washHandCost * rate);
    brushCost += (brushCost * rate);
}
double Grooming::getBathCost() const
{
    return bathCost;
}

void Grooming::setBathCost(double value)
{
    bathCost = value;
}

double Grooming::getLaundryCost() const
{
    return laundryCost;
}

void Grooming::setLaundryCost(double value)
{
    laundryCost = value;
}

double Grooming::getWashHandCost() const
{
    return washHandCost;
}

void Grooming::setWashHandCost(double value)
{
    washHandCost = value;
}

double Grooming::getBrushCost() const
{
    return brushCost;
}

void Grooming::setBrushCost(double value)
{
    brushCost = value;
}
