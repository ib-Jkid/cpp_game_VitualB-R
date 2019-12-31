#ifndef KITCHEN_H
#define KITCHEN_H


class Kitchen
{
public:
    Kitchen();

    double getRiceCost() const;
    void setRiceCost(double value);

    double getPotatoCost() const;
    void setPotatoCost(double value);

    double getSpagettiCost() const;
    void setSpagettiCost(double value);

    double getBeansCost() const;
    void setBeansCost(double value);

    double getEnergyDrinkCost() const;
    void setEnergyDrinkCost(double value);

    double getCarrotCost() const;
    void setCarrotCost(double value);

    bool buyRice(bool spent);
    bool buyCarrot(bool spent);
    bool buyBeans(bool spent);
    bool buySpagetti(bool spent);
    bool energyDrink(bool spent);
    bool buyPotatoes(bool spent);

    void gameCycle(double rate);

private:
    double riceCost;
    double potatoCost;
    double spagettiCost;
    double beansCost;
    double energyDrinkCost;
    double carrotCost;

    unsigned int rice;
    unsigned int potato;
    unsigned int beans;
    unsigned int carrot;
};

#endif // KITCHEN_H
