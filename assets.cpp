#include "assets.h"

Assets::Assets()
{
    loanLimit = 0.0;
    accumulatedIncome = 0.0;
    incomePerCycle = 0.0;
    accumulatedIncomeLimit = 500000.0;

    factoryOwned = 0;
    houseOwned = 0;
    refineryOwned = 0;
    bankOwned = 0;


    houseCost = 19500.0;
    refineryCost = 1300000.0;
    bankCost = 500000.0;
    factoryCost = 130000.0;

    factoryIncome = 13000.0;
    houseIncome = 1000.0;
    refineryIncome = 150000.0;
    bankIncome = 50000.0;


}

void Assets::gameCycle(double rate) {
    houseCost += (houseCost * rate );
    refineryCost += (refineryCost * rate );
    bankCost += (bankCost * rate );
    factoryCost += (factoryCost * rate );

    factoryIncome += (factoryIncome * rate);
    houseIncome += (houseIncome * rate);
    refineryIncome += (refineryIncome * rate);
    bankIncome += (bankIncome * rate);

    if(accumulatedIncome < accumulatedIncomeLimit) {
        accumulatedIncome += getIncomePerCycle();
        if(accumulatedIncome > accumulatedIncomeLimit) {
            accumulatedIncome = accumulatedIncomeLimit;
        }
    }
    loanLimit = getTotalAssetWorth() * 2;
}
double Assets::getTotalAssetWorth() {
    return ((bankOwned * bankCost) +
            (houseOwned * houseCost)+
            (refineryOwned * refineryCost)+
            (factoryOwned * factoryCost) );
}

double Assets::getTotalIncome()
{
    return  ((bankOwned * bankIncome) +
             (houseOwned * houseIncome)+
             (refineryOwned * refineryIncome)+
             (factoryOwned * factoryIncome) );
}

double Assets::getLoanLimit() const
{
    return loanLimit;
}

void Assets::setLoanLimit(double value)
{
    loanLimit = value;
}

unsigned int Assets::getFactoryOwned() const
{
    return factoryOwned;
}

void Assets::setFactoryOwned(unsigned int value)
{
    factoryOwned = value;
}

unsigned int Assets::getHouseOwned() const
{
    return houseOwned;
}

void Assets::setHouseOwned(unsigned int value)
{
    houseOwned = value;
}

unsigned int Assets::getRefineryOwned() const
{
    return refineryOwned;
}

void Assets::setRefineryOwned(unsigned int value)
{
    refineryOwned = value;
}

unsigned int Assets::getBankOwned() const
{
    return bankOwned;
}

void Assets::setBankOwned(unsigned int value)
{
    bankOwned = value;
}

double Assets::getFactoryCost() const
{
    return factoryCost;
}

void Assets::setFactoryCost(double value)
{
    factoryCost = value;
}

double Assets::getHouseCost() const
{
    return houseCost;
}

void Assets::setHouseCost(double value)
{
    houseCost = value;
}

double Assets::getRefineryCost() const
{
    return refineryCost;
}

void Assets::setRefineryCost(double value)
{
    refineryCost = value;
}

double Assets::getBankCost() const
{
    return bankCost;
}

void Assets::setBankCost(double value)
{
    bankCost = value;
}

double Assets::getFactoryIncome() const
{
    return factoryIncome;
}

void Assets::setFactoryIncome(double value)
{
    factoryIncome = value;
}

double Assets::getHouseIncome() const
{
    return houseIncome;
}

void Assets::setHouseIncome(double value)
{
    houseIncome = value;
}

double Assets::getRefineryIncome() const
{
    return refineryIncome;
}

void Assets::setRefineryIncome(double value)
{
    refineryIncome = value;
}

double Assets::getBankIncome() const
{
    return bankIncome;
}

void Assets::setBankIncome(double value)
{
    bankIncome = value;
}


double Assets::getAccumulatedIncome() const
{
    return accumulatedIncome;
}

void Assets::setAccumulatedIncome(double value)
{
    accumulatedIncome = value;
}

double Assets::getIncomePerCycle() const
{
    return (
                (factoryIncome*factoryOwned)+
                (houseIncome*houseOwned)+
                (refineryIncome*refineryOwned)+
                (bankIncome*bankOwned)
                );
}

void Assets::setIncomePerCycle(double value)
{
    incomePerCycle = value;
}

double Assets::buyFactory(int num,  double money)
{
    double totalCost = num * factoryCost;
    if(totalCost <= money) {
        factoryOwned += num;
        return totalCost;
    }
    return 0.0;
}

double Assets::buyHouse(int num, double money)
{
    double totalCost = num * houseCost;
    if(totalCost <= money) {
        houseOwned += num;
        return totalCost;
    }
    return 0.0;
}

double Assets::buyBank(int num, double money)
{
    double totalCost = num * bankCost;
    if(totalCost <= money) {
        bankOwned += num;
        return totalCost;
    }
    return 0.0;
}

double Assets::buyRefinery(int num, double money)
{
    double totalCost = num * refineryCost;
    if(totalCost <= money) {
        refineryOwned += num;
        return totalCost;
    }
    return 0.0;
}

double Assets::sellFactory(unsigned int num)
{
    if(factoryOwned >= num) {
        double cost = num * factoryCost;
        factoryOwned -= num;
        return cost;
    }

    return 0.0;
}

double Assets::sellHouse(unsigned int num)
{
    if(houseOwned >= num) {
        double cost = num * houseCost;
        houseOwned -= num;
        return cost;
    }

    return 0.0;
}

double Assets::sellBank(unsigned int num)
{
    if(bankOwned >= num) {
        double cost = num * bankCost;
        bankOwned -= num;
        return cost;
    }

    return 0.0;
}

double Assets::sellRefinery(unsigned int num)
{
    if(refineryOwned >= num) {
        double cost = num * refineryCost;
        refineryOwned -= num;
        return cost;
    }

    return 0.0;
}

double Assets::collectIncome()
{
    if(accumulatedIncome > 0) {
        double fund = accumulatedIncome;
        accumulatedIncome = 0.0;
        return fund;
    }
    return 0.0;
}

int Assets::getProgress() const{
    if(accumulatedIncome > 0){
        return (accumulatedIncome * 100 / accumulatedIncomeLimit);
    }
    return 0;

}

