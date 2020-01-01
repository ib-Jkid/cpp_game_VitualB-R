#include "bank.h"

Bank::Bank()
{
    accountBalance = 100.0;
    dept = 0.0;
    moneyAtHand = 100.0;
    charges = 1.0;

    schoolLoanLimit = 700.0;
    schoolLoan = 0.0;
    schoolPayRate = 11;
}

double Bank::getFinancialSummary() {
    return (
        accountBalance + moneyAtHand - dept
                );
}

double Bank::collectSchoolLoan()
{
    if(schoolLoan == 0.0) {
        schoolLoan = schoolLoanLimit + (schoolLoanLimit / 100 * 10);
        return schoolLoanLimit;
    }
    return 0.0;

}

double Bank::paySchoolLoan()
{
    if(schoolLoan > 0.0) {
        schoolLoan -= schoolPayRate;
        return schoolPayRate;
    }
    return 0.0;

}

double Bank::getSchoolPayRate() const
{
    return schoolPayRate;
}

void Bank::setSchoolPayRate(double value)
{
    schoolPayRate = value;
}

double Bank::getSchoolLoanLimit() const
{
    return schoolLoanLimit;
}

void Bank::setSchoolLoanLimit(double value)
{
    schoolLoanLimit = value;
}

double Bank::getSchoolLoan() const
{
    return schoolLoan;
}

void Bank::setSchoolLoan(double value)
{
    schoolLoan = value;
}
void Bank::gameCycle(double rate) {
    loose(charges);
    loose(paySchoolLoan());
    dept += (dept * rate);
    accountBalance += (accountBalance * rate / 10);
}

double Bank::getAccountBalance() const
{
    return accountBalance;
}

void Bank::setAccountBalance(double value)
{
    accountBalance = value;
}

double Bank::getDept() const
{
    return dept;
}

void Bank::setDept(double value)
{
    dept = value;
}

bool Bank::deposite(double amount)
{
    if(moneyAtHand >= (amount+charges)) {
        moneyAtHand -= (amount+charges);
        accountBalance += amount;
        return true;
    }
    return false;
}

bool Bank::withdraw(double amount)
{
    if(accountBalance >= (amount+charges)){
        accountBalance -= (amount+charges);
        moneyAtHand += amount;
        return true;
    }
    return false;
}

bool Bank::processLoan(double amount, double limit)
{
    if(limit >= (amount+dept) ) {
        dept += amount;
        accountBalance += (amount - charges);
        return true;
    }
    return false;
}

bool Bank::payDept()
{
    if(moneyAtHand >= dept) {
        moneyAtHand -= dept;
        dept = 0.0;
        return true;
    }else if(accountBalance >= dept) {
        accountBalance -= dept;
        dept = 0.0;
        return true;
    }else if(dept > 0 && (moneyAtHand > 0 || accountBalance > 0)) {
        dept -= moneyAtHand;
        moneyAtHand = 0;
        if(accountBalance >= dept) {
            accountBalance -= dept;
            dept = 0.0;
        }else if(dept > 0 && accountBalance > 0) {
            dept -= accountBalance;
            accountBalance = 0;
        }
        return true;
    }
    return false;
}

bool Bank::recieveEarnings(double salary)
{
    accountBalance += (salary - (salary * 10 / 100) );
    return true;
}

double Bank::getMoneyAtHand() const
{
    return moneyAtHand;
}

void Bank::setMoneyAtHand(double value)
{
    moneyAtHand = value;
}

double Bank::getCharges() const
{
    return charges;
}

void Bank::setCharges(double value)
{
    charges = value;
}

bool Bank::spend(double amount)
{
    if(moneyAtHand >= amount && amount != 0.0) {
        moneyAtHand -= amount;
        return true;
    }
    return false;
}

bool Bank::earn(double amount)
{
    if(amount != 0.0) {
        moneyAtHand += amount;
        return true;
    }
    return false;

}

bool Bank::loose(double amount)
{
    if(moneyAtHand >= amount) {
        moneyAtHand -= amount;
        return true;
    }
    if(accountBalance >= amount) {
        accountBalance -= amount;
        return true;
    }

    if((moneyAtHand+accountBalance) >= amount){
        double rem = amount;
        rem -= moneyAtHand;
        moneyAtHand = 0;
        accountBalance -= rem;
        return true;
    }
    if((moneyAtHand+accountBalance) < amount) {
        double rem = amount;
        rem -= moneyAtHand;
        rem -= accountBalance;
        moneyAtHand = 0;
        accountBalance = 0;
        dept += rem;
        return true;
    }
    return false;
}
