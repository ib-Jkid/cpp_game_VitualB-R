#include "expenses.h"

Expenses::Expenses()
{
    car = false;
    thugs = false;
    bodyGuard = false;
    lawyer = false;
    house = false;
    nurse = false;
    renting = false;
    mortgaging = false;

    carCost = 5000.0;
    thugSalary = 100.0;
    bodyGuardSalary = 200.0;
    lawyerSalary = 300.0;
    houseCost = 20000.0;
    houseMotgageDownPayment = 5000.0;
    motgageCyclePayment = 500.0;
    nurseSalary = 250.0;
    houseRent = 35.0;
}

bool Expenses::rentAHouse() {
    house = true;
    return renting = true;
}

bool Expenses::stopRentingHouse() {
    house = false;
    renting = false;
    return true;
}

bool Expenses::initiateMortgageContract()
{
    houseCost += motgageCyclePayment;
    houseCost -= houseMotgageDownPayment;
    mortgaging = true;
    return house = true;

}

double Expenses::getExpenses()  {
    double expense = 0.0;
    if(thugs) {
        expense+= thugSalary;
    }
    if(bodyGuard) {
        expense+=bodyGuardSalary;
    }
    if(lawyer) {
        expense += lawyerSalary;
    }
    if(nurse) {
        expense += nurseSalary;
    }
    if(renting) {
        expense += houseRent;
    }
    if(mortgaging) {
        expense += motgageCyclePayment;
        houseCost -= motgageCyclePayment;
    }
    return expense;
}
void Expenses::gameCycle(double rate) {
    carCost += (carCost * rate);
    thugSalary += (thugSalary * rate);
    bodyGuardSalary += (bodyGuardSalary * rate);
    lawyerSalary += (lawyerSalary * rate);
    houseCost += (houseCost * rate);
    nurseSalary += (nurseSalary * rate);
}

bool Expenses::getRenting() const
{
    return renting;
}

void Expenses::setRenting(bool value)
{
    renting = value;
}

double Expenses::getHouseRent() const
{
    return houseRent;
}

void Expenses::setHouseRent(double value)
{
    houseRent = value;
}

double Expenses::getHouseMotgageDownPayment() const
{
    return houseMotgageDownPayment;
}

void Expenses::setHouseMotgageDownPayment(double value)
{
    houseMotgageDownPayment = value;
}

double Expenses::getMotgageCyclePayment() const
{
    return motgageCyclePayment;
}

void Expenses::setMotgageCyclePayment(double value)
{
    motgageCyclePayment = value;
}

bool Expenses::getMortgaging() const
{
    return mortgaging;
}

void Expenses::setMortgaging(bool value)
{
    mortgaging = value;
}
bool Expenses::hireBodyGuard()
{
    if(bodyGuard) {
        return false;
    }
    return (bodyGuard = true);

}

bool Expenses::hireLawyer()
{
    if(lawyer) {
        return false;
    }
    return (lawyer = true);
}

bool Expenses::buyCar(bool spent)
{
    if(car || !spent) {
        return false;
    }
    return (car = true);

}

bool Expenses::buyHouse(bool spent)
{
    if(house || !spent) {
        return false;
    }
    return (house = true);
}

double Expenses::sellHouse()
{
    if(!house) {
        return 0.0;
    }
    house = false;
    return (houseCost / 2);
}

double Expenses::sellCar()
{
    if(!car) {
        return 0.0;
    };
    car = false;
    return (carCost/2);
}

bool Expenses::dismissBodyGuard(bool spent)
{
    if(!spent || !bodyGuard) {
        return false;
    }
    bodyGuard = false;
    return true;
}

bool Expenses::dismissThugs(bool spent)
{
    if(!spent || !thugs) {
        return false;
    }
    thugs = false;
    return true;
}

bool Expenses::dismissLawyer(bool spent)
{
    if(!spent || !lawyer) {
        return false;
    }
   lawyer = false;
   return true;
}

bool Expenses::dismissNurse(bool spent)
{
    if(!spent || !nurse) {
        return false;
    }

    nurse = false;
    return true;
}

bool Expenses::hireThugs()
{
    if(thugs) {
        return false;
    }
    return (thugs = true);
}

bool Expenses::hireNurse()
{
    if(nurse) {
        return false;
    }
    return (nurse = true);
}

bool Expenses::hasCar() const
{
    return car;
}

void Expenses::setCar(bool value)
{
    car = value;
}

bool Expenses::hasThugs() const
{
    return thugs;
}

void Expenses::setThugs(bool value)
{
    thugs = value;
}

bool Expenses::hasBodyGuard() const
{
    return bodyGuard;
}

void Expenses::setBodyGuard(bool value)
{
    bodyGuard = value;
}

bool Expenses::hasLawyer() const
{
    return lawyer;
}

void Expenses::setLawyer(bool value)
{
    lawyer = value;
}

bool Expenses::hasHouse() const
{
    return house;
}

void Expenses::setHouse(bool value)
{
    house = value;
}

double Expenses::getCarCost() const
{
    return carCost;
}

void Expenses::setCarCost(double value)
{
    carCost = value;
}

double Expenses::getThugSalary() const
{
    return thugSalary;
}

void Expenses::setThugSalary(double value)
{
    thugSalary = value;
}

double Expenses::getBodyGuardSalary() const
{
    return bodyGuardSalary;
}

void Expenses::setBodyGuardSalary(double value)
{
    bodyGuardSalary = value;
}

double Expenses::getLawyerSalary() const
{
    return lawyerSalary;
}

void Expenses::setLawyerSalary(double value)
{
    lawyerSalary = value;
}

double Expenses::getHouseCost() const
{
    return houseCost;
}

void Expenses::setHouseCost(double value)
{
    houseCost = value;
}

double Expenses::getNurseSalary() const
{
    return nurseSalary;
}

void Expenses::setNurseSalary(double value)
{
    nurseSalary = value;
}

bool Expenses::hasNurse() const
{
    return nurse;
}

void Expenses::setNurse(bool value)
{
    nurse = value;
}
