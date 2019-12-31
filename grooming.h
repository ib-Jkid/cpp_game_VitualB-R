#ifndef GROOMING_H
#define GROOMING_H


class Grooming
{
public:
    Grooming();

    double getBathCost() const;
    void setBathCost(double value);

    double getLaundryCost() const;
    void setLaundryCost(double value);

    double getWashHandCost() const;
    void setWashHandCost(double value);

    double getBrushCost() const;
    void setBrushCost(double value);
    void gameCycle(double rate);

private:
    double bathCost;
    double laundryCost;
    double washHandCost;
    double brushCost;
};

#endif // GROOMING_H
