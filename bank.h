#ifndef BANK_H
#define BANK_H

class Bank
{
public:
    Bank();
    double getAccountBalance() const;
    void setAccountBalance(double value);


    double getDept() const;
    void setDept(double value);

    bool deposite(double amount);
    bool withdraw(double amount);
    bool processLoan(double amount, double limit);
    bool payDept();
    bool recieveEarnings(double salary);

    double getMoneyAtHand() const;
    void setMoneyAtHand(double value);

    double getCharges() const;
    void setCharges(double value);

    bool spend(double amount);

    bool earn(double amount);

    bool loose(double amount);

    void gameCycle(double rate);

    double getFinancialSummary();

    double collectSchoolLoan();
    double paySchoolLoan();

    double getSchoolPayRate() const;
    void setSchoolPayRate(double value);

    double getSchoolLoanLimit() const;
    void setSchoolLoanLimit(double value);

    double getSchoolLoan() const;
    void setSchoolLoan(double value);

private:
    double accountBalance;
    double dept;
    double moneyAtHand;
    double charges;
    double schoolLoanLimit;
    double schoolLoan;
    double schoolPayRate;

};

#endif // BANK_H
