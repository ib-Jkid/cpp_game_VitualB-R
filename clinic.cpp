#include "clinic.h"

Clinic::Clinic()
{
    pillCost = 4.0;
    injectionCost = 6.0;
    hospitalBill = 50.0;
    checkupBill = 2.0;
}

void Clinic::gameCycle(double rate) {
    pillCost += (pillCost * rate);
    injectionCost += (injectionCost * rate);
    hospitalBill += (hospitalBill * rate);
    checkupBill += (checkupBill * rate);
}

bool Clinic::buyPill(bool spent)
{
    if(spent) {
        return true;
    }
    return false;
}

bool Clinic::buyInjection(bool spent)
{
    if(spent) {
        return true;
    }
    return false;
}

bool Clinic::payCheckup(bool spent)
{
    if(spent) {
        return true;
    }
    return false;
}

bool Clinic::payHospitalBill(bool spent)
{
    if(spent) {
        return true;
    }
    return false;
}

double Clinic::getPillCost() const
{
    return pillCost;
}

void Clinic::setPillCost(double value)
{
    pillCost = value;
}

double Clinic::getInjectionCost() const
{
    return injectionCost;
}

void Clinic::setInjectionCost(double value)
{
    injectionCost = value;
}

double Clinic::getHospitalBill() const
{
    return hospitalBill;
}

void Clinic::setHospitalBill(double value)
{
    hospitalBill = value;
}

double Clinic::getCheckupBill() const
{
    return checkupBill;
}

void Clinic::setCheckupBill(double value)
{
    checkupBill = value;
}
