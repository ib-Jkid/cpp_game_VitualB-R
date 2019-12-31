#ifndef CRIME_H
#define CRIME_H


#include <stdlib.h>
#include <time.h>

class Crime
{
public:
    Crime();
    double commitRobbery();
    double commitBankFraud();
    double commitTheft();

    int getRobberyChance() const;


    int getTheftChance() const;


    int getBankChance() const;


private:
    double robberyGain;
    double theftGain;
    double bankFraudGain;
    int robberyChance;
    int theftChance;
    int bankFraudChance;

};

#endif // CRIME_H
