#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();

    bool isFree() const;
    void setFree(bool value);

    bool eatRice(bool rice);
    bool eatBeans(bool beans);
    bool eatCarrots(bool carrots);
    bool eatPotatoes(bool potatoes);
    bool eatSpaghetti(bool spaghetti);
    bool energyDrink(bool energyDrink);


    bool takePill(bool pill);
    bool takeInjection(bool injection);
    bool doCheckUp(bool checkup);
    bool hospitalDischarge(bool hospital);

    bool takeBath(bool spent);
    bool brushTeeth(bool spent);
    bool washHand(bool spent);
    bool doLaundry(bool spent);

    unsigned int getHealthStatus() const;
    void setHealthStatus(unsigned int value);

    unsigned int getEnergy() const;
    void setEnergy(unsigned int value);

    unsigned int getStarvationLevel() const;
    void setStarvationLevel(unsigned int value);

    unsigned int getGroomingLevel() const;
    void setGroomingLevel(unsigned int value);

    bool isDead() const;
    void setDead(bool value);

    int getRiceOnHunger() const;
    void setRiceOnHunger(int value);

    int getBeansOnHunger() const;
    void setBeansOnHunger(int value);

    int getCarrotsOnHunger() const;
    void setCarrotsOnHunger(int value);

    int getPotatoesOnHunger() const;
    void setPotatoesOnHunger(int value);

    int getSpaghettiOnHunger() const;
    void setSpaghettiOnHunger(int value);

    int getEnergyDrinkOnHunger() const;
    void setEnergyDrinkOnHunger(int value);

    int getRiceOnEnergy() const;
    void setRiceOnEnergy(int value);

    int getBeansOnEnergy() const;
    void setBeansOnEnergy(int value);

    int getCarrotsOnEnergy() const;
    void setCarrotsOnEnergy(int value);

    int getPotatoesOnEnergy() const;
    void setPotatoesOnEnergy(int value);

    int getSpaghettiOnEnergy() const;
    void setSpaghettiOnEnergy(int value);

    int getEnergyDrinkOnEnergy() const;
    void setEnergyDrinkOnEnergy(int value);

    bool isSick() const;
    void setSick(bool value);

    int getHospitalOnHealth() const;
    void setHospitalOnHealth(int value);

    void gameCycle();

private:
    bool free;
    bool dead;
    bool sick;
    int starvationLevel;
    int energy;
    int healthStatus;
    int groomingLevel;

    int riceOnHunger;
    int beansOnHunger;
    int carrotsOnHunger;
    int potatoesOnHunger;
    int spaghettiOnHunger;
    int energyDrinkOnHunger;

    int riceOnEnergy;
    int beansOnEnergy;
    int carrotsOnEnergy;
    int potatoesOnEnergy;
    int spaghettiOnEnergy;
    int energyDrinkOnEnergy;

    int pillOnHealth;
    int injectionOnHealth;
    int checkupOnHealth;
    int hospitalOnHealth;

    int washHandOnGrooming;
    int bathOnGrooming;
    int laundryOnGRooming;
    int brushOnGrooming;

};

#endif // PLAYER_H
