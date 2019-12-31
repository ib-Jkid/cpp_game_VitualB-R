#ifndef EXPENSES_H
#define EXPENSES_H


class Expenses
{
public:
    Expenses();
    double getExpenses();
    bool hireBodyGuard();
    bool hireLawyer();
    bool buyCar(bool spent);
    bool buyHouse(bool spent);
    double sellHouse();
    double sellCar();
    bool dismissBodyGuard(bool spent);
    bool dismissThugs(bool spent);
    bool dismissLawyer(bool spent);
    bool dismissNurse(bool spent);
    bool hireThugs();
    bool hireNurse();
    bool rentAHouse();
    bool stopRentingHouse();
    bool initiateMortgageContract();

    bool hasCar() const;
    void setCar(bool value);

    bool hasThugs() const;
    void setThugs(bool value);

    bool hasBodyGuard() const;
    void setBodyGuard(bool value);

    bool hasLawyer() const;
    void setLawyer(bool value);

    bool hasHouse() const;
    void setHouse(bool value);

    double getCarCost() const;
    void setCarCost(double value);

    double getThugSalary() const;
    void setThugSalary(double value);

    double getBodyGuardSalary() const;
    void setBodyGuardSalary(double value);

    double getLawyerSalary() const;
    void setLawyerSalary(double value);

    double getHouseCost() const;
    void setHouseCost(double value);

    double getNurseSalary() const;
    void setNurseSalary(double value);

    bool hasNurse() const;
    void setNurse(bool value);

    void gameCycle(double rate);

    bool getRenting() const;
    void setRenting(bool value);

    double getHouseRent() const;
    void setHouseRent(double value);

    double getHouseMotgageDownPayment() const;
    void setHouseMotgageDownPayment(double value);

    double getMotgageCyclePayment() const;
    void setMotgageCyclePayment(double value);

    bool getMortgaging() const;
    void setMortgaging(bool value);

private:

    bool car;
    bool thugs;
    bool bodyGuard;
    bool lawyer;
    bool house;
    bool nurse;
    bool renting;
    bool mortgaging;

    double carCost;
    double thugSalary;
    double bodyGuardSalary;
    double lawyerSalary;
    double houseCost;
    double nurseSalary;
    double houseRent;
    double houseMotgageDownPayment;
    double motgageCyclePayment;
};

#endif // EXPENSES_H
