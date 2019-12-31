#include "crime.h"

Crime::Crime()
{
    robberyGain = 3000;
    theftGain = 1000;
    bankFraudGain = 7000;
    robberyChance = 30;
    theftChance = 50;
    bankFraudChance = 10;

    srand (time(NULL));



}

double Crime::commitRobbery()
{
    int random = rand() % 100 + 1;
    if(random <= robberyChance) {
        if(robberyChance < 80) {
            robberyChance += 2;
        }
        return robberyGain;
    }
    return 0.0;
}

double Crime::commitBankFraud()
{
    int random = rand() % 100 + 1;
    if(random <= bankFraudChance) {
        if(bankFraudChance < 80) {
            bankFraudChance += 2;
         }


        return bankFraudGain;
    }
    return 0.0;
}

double Crime::commitTheft()
{
    int random = rand() % 100 + 1;
    if(random <= theftChance) {
        if(theftChance < 80) {
            theftChance += 2;
        }

        return theftGain;
    }
    return 0.0;
}

int Crime::getRobberyChance() const
{
    return robberyChance;
}



int Crime::getTheftChance() const
{
    return theftChance;
}



int Crime::getBankChance() const
{
    return bankFraudChance;
}


