#ifndef CLINIC_H
#define CLINIC_H


class Clinic
{
public:
    Clinic();

    bool buyPill(bool spent);
    bool buyInjection(bool spent);
    bool payCheckup(bool spent);
    bool payHospitalBill(bool spent);

    double getPillCost() const;
    void setPillCost(double value);

    double getInjectionCost() const;
    void setInjectionCost(double value);

    double getHospitalBill() const;
    void setHospitalBill(double value);

    double getCheckupBill() const;
    void setCheckupBill(double value);

    void gameCycle(double rate);

private:
    double pillCost;
    double injectionCost;
    double hospitalBill;
    double checkupBill;
};

#endif // CLINIC_H
