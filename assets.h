#ifndef ASSETS_H
#define ASSETS_H


#include "bank.h"

class Assets
{
public:
    Assets();

    double getLoanLimit() const;
    void setLoanLimit(double value);

    unsigned int getFactoryOwned() const;
    void setFactoryOwned(unsigned int value);

    unsigned int getHouseOwned() const;
    void setHouseOwned(unsigned int value);

    unsigned int getRefineryOwned() const;
    void setRefineryOwned(unsigned int value);

    unsigned int getBankOwned() const;
    void setBankOwned(unsigned int value);

    double getFactoryCost() const;
    void setFactoryCost(double value);

    double getHouseCost() const;
    void setHouseCost(double value);

    double getRefineryCost() const;
    void setRefineryCost(double value);

    double getBankCost() const;
    void setBankCost(double value);

    double getFactoryIncome() const;
    void setFactoryIncome(double value);

    double getHouseIncome() const;
    void setHouseIncome(double value);

    double getRefineryIncome() const;
    void setRefineryIncome(double value);

    double getBankIncome() const;
    void setBankIncome(double value);

    int getProgress() const;

    double getAccumulatedIncome() const;
    void setAccumulatedIncome(double value);

    double getIncomePerCycle() const;
    void setIncomePerCycle(double value);

    double buyFactory(int num, double money);
    double buyHouse(int num,  double money);
    double buyBank(int num,  double money);
    double buyRefinery(int num,  double money);

    double sellFactory(unsigned int num);
    double sellHouse(unsigned int num);
    double sellBank(unsigned int num);
    double sellRefinery(unsigned int num);

    double collectIncome();

    void gameCycle(double rate);
    double getTotalAssetWorth();

    double getTotalIncome();

private:
    double loanLimit;
    unsigned int factoryOwned;
    unsigned int houseOwned;
    unsigned int refineryOwned;
    unsigned int bankOwned;

    double factoryCost;
    double houseCost;
    double refineryCost;
    double bankCost;

    double factoryIncome;
    double houseIncome;
    double refineryIncome;
    double bankIncome;

    double accumulatedIncome;
    double incomePerCycle;

    int accumulatedIncomeLimit;

};

#endif // ASSETS_H
