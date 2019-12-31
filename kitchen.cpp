#include "kitchen.h"

Kitchen::Kitchen()
{
    riceCost = 50.0;
    potatoCost = 50.0;
    spagettiCost = 60.0;
    beansCost = 70.0;
    energyDrinkCost = 100.0;
    carrotCost = 40.0;

    rice = 0;
    potato = 0;
    beans = 0;
    carrot = 0;
}

void Kitchen::gameCycle(double rate) {
    riceCost += (riceCost * rate);
    potatoCost += (potatoCost * rate);
    spagettiCost += (spagettiCost * rate);
    beansCost += (beansCost * rate);
    energyDrinkCost += (energyDrinkCost * rate);
    carrotCost += (carrotCost * rate);
}

double Kitchen::getRiceCost() const
{
    return riceCost;
}

void Kitchen::setRiceCost(double value)
{
    riceCost = value;
}

double Kitchen::getPotatoCost() const
{
    return potatoCost;
}

void Kitchen::setPotatoCost(double value)
{
    potatoCost = value;
}

double Kitchen::getSpagettiCost() const
{
    return spagettiCost;
}

void Kitchen::setSpagettiCost(double value)
{
    spagettiCost = value;
}

double Kitchen::getBeansCost() const
{
    return beansCost;
}

void Kitchen::setBeansCost(double value)
{
    beansCost = value;
}

double Kitchen::getEnergyDrinkCost() const
{
    return energyDrinkCost;
}

void Kitchen::setEnergyDrinkCost(double value)
{
    energyDrinkCost = value;
}

double Kitchen::getCarrotCost() const
{
    return carrotCost;
}

void Kitchen::setCarrotCost(double value)
{
    carrotCost = value;
}

bool Kitchen::buyRice(bool spent)
{
    if(rice > 0) {\
        rice--;
        return true;
    }else if(spent) {

        return true;
    }
    return false;
}

bool Kitchen::buyCarrot(bool spent)
{
    if(carrot > 0) {
        carrot--;
        return true;
    }else if(spent) {

        return true;
    }
    return false;

}

bool Kitchen::buyBeans(bool spent)
{
    if(beans > 0) {
         beans--;
        return true;
    }else if(spent) {

        return true;
    }
    return false;

}

bool Kitchen::buySpagetti(bool spent)
{
    if(spent) {
        return true;
    }
    return false;

}

bool Kitchen::energyDrink(bool spent)
{
    if(spent) {
        return true;
    }
    return false;

}

bool Kitchen::buyPotatoes(bool spent)
{
    if(potato > 0) {
        potato--;
        return true;
    }else if(spent) {

        return true;
    }
    return false;
}

