#include "player.h"

Player::Player()
{
    free = true;
    dead = false;
    sick = false;
    starvationLevel = 100;
    energy = 100;
    healthStatus = 100;
    groomingLevel = 100;

    riceOnHunger = 20;
    beansOnHunger = 40;
    carrotsOnHunger = 30;
    potatoesOnHunger = 15;
    spaghettiOnHunger = 10;
    energyDrinkOnHunger = 5;

    riceOnEnergy = 30;
    beansOnEnergy = 15;
    carrotsOnEnergy = 20;
    potatoesOnEnergy = 25;
    spaghettiOnEnergy = 20;
    energyDrinkOnEnergy = 50;

    pillOnHealth = 10;
    injectionOnHealth = 20;
    checkupOnHealth = 7;
    hospitalOnHealth = 100;

    washHandOnGrooming = 1;
    bathOnGrooming = 15;
    laundryOnGRooming = 50;
    brushOnGrooming = 7;

}

void Player::gameCycle() {
    starvationLevel -= 10;
    energy -= 10;
    healthStatus -= 10;
    groomingLevel -= 10;

    if(groomingLevel <= 10) {
        healthStatus -= 10;
    }
    if(energy <= 10) {
        healthStatus -= 10;
    }
    if(starvationLevel <= 10) {
        healthStatus -= 10;
    }
    if(!free) {
        healthStatus -= 10;
    }
    if(healthStatus < 0) {
        dead = true;
    }else if(healthStatus < 20) {
        sick = true;
    }
}

bool Player::isFree() const
{
    return free;
}

void Player::setFree(bool value)
{
    free = value;
}

bool Player::eatRice(bool rice)
{
    if(rice) {
        energy += riceOnEnergy;
        starvationLevel += riceOnHunger;
        if(energy > 100) {
            energy = 100;
        }
        if(starvationLevel > 100) {
            starvationLevel = 100;
        }
        return true;
    }
    return false;




}

bool Player::eatBeans(bool beans)
{
    if(beans) {
        energy += beansOnEnergy;
        starvationLevel += beansOnHunger;
        if(starvationLevel > 100) {
            starvationLevel = 100;
        }
        if(energy > 100) {
            energy = 100;
        }
        return true;
    }
    return false;

}

bool Player::eatCarrots(bool carrots)
{
    if(carrots) {
         energy += carrotsOnEnergy;
         starvationLevel += carrotsOnHunger;
         if(starvationLevel > 100) {
             starvationLevel = 100;
         }
         if(energy > 100) {
             energy = 100;
         }
         return true;
    }
    return false;

}

bool Player::eatPotatoes(bool potatoes)
{
    if(potatoes) {
        energy += potatoesOnEnergy;
        starvationLevel += potatoesOnHunger;
        if(starvationLevel > 100) {
            starvationLevel = 100;
        }
        if(energy > 100) {
            energy = 100;
        }
        return true;
    }
    return false;
}

bool Player::eatSpaghetti(bool spaghetti)
{
    if(spaghetti) {
        energy += spaghettiOnEnergy;
        starvationLevel += spaghettiOnHunger;
        if(starvationLevel > 100) {
            starvationLevel = 100;
        }
        if(energy > 100) {
            energy = 100;
        }
        return true;
    }
    return false;
}

bool Player::energyDrink(bool energyDrink)
{
    if(energyDrink) {
        energy += energyDrinkOnEnergy;
        starvationLevel += energyDrinkOnHunger;
        if(starvationLevel > 100) {
            starvationLevel = 100;
        }
        if(energy > 100) {
            energy = 100;
        }
        return true;
    }
    return false;
}

bool Player::takeBath(bool spent)
{
    if(spent) {
        groomingLevel += bathOnGrooming;
        if(groomingLevel > 100) {
            groomingLevel = 100;
        }
        return true;
    }
    return false;

}

bool Player::brushTeeth(bool spent)
{
    if(spent) {
        groomingLevel += brushOnGrooming;
        if(groomingLevel > 100) {
            groomingLevel = 100;
        }
        return true;
    }
    return false;
}

bool Player::washHand(bool spent)
{
    if(spent) {
        groomingLevel += washHandOnGrooming;
        if(groomingLevel > 100) {
            groomingLevel = 100;
        }
        return true;
    }
    return false;

}

bool Player::doLaundry(bool spent)
{
    if(spent) {
        groomingLevel += laundryOnGRooming;
        if(groomingLevel > 100) {
            groomingLevel = 100;
        }
        return true;
    }
    return false;

}

bool Player::takePill(bool pill)
{
    if(pill) {
        healthStatus += pillOnHealth;
        if(healthStatus > 100){
            healthStatus = 100;
        }
        return true;
    }
    return false;

}

bool Player::takeInjection(bool injection)
{
    if(injection) {
        healthStatus += injectionOnHealth;
        if(healthStatus > 100){
            healthStatus = 100;
        }
        return true;
    }
    return false;
}

bool Player::doCheckUp(bool checkup)
{
    if(checkup) {
        healthStatus += checkupOnHealth;
        if(healthStatus > 100){
            healthStatus = 100;
        }
        return true;
    }
    return false;
}

bool Player::hospitalDischarge(bool hospital)
{
    if(hospital) {
        healthStatus += hospitalOnHealth;
        if(healthStatus > 100){
            healthStatus = 100;
        }
        return true;
    }
    return false;
}

unsigned int Player::getHealthStatus() const
{
    return healthStatus;
}

void Player::setHealthStatus(unsigned int value)
{
    healthStatus = value;
}

unsigned int Player::getEnergy() const
{
    return energy;
}

void Player::setEnergy(unsigned int value)
{
    energy = value;
}

unsigned int Player::getStarvationLevel() const
{
    return starvationLevel;
}

void Player::setStarvationLevel(unsigned int value)
{
    starvationLevel = value;
}

unsigned int Player::getGroomingLevel() const
{
    return groomingLevel;
}

void Player::setGroomingLevel(unsigned int value)
{
    groomingLevel = value;
}

bool Player::isDead() const
{
    return dead;
}

void Player::setDead(bool value)
{
    dead = value;
}

int Player::getRiceOnHunger() const
{
    return riceOnHunger;
}

void Player::setRiceOnHunger(int value)
{
    riceOnHunger = value;
}

int Player::getBeansOnHunger() const
{
    return beansOnHunger;
}

void Player::setBeansOnHunger(int value)
{
    beansOnHunger = value;
}

int Player::getCarrotsOnHunger() const
{
    return carrotsOnHunger;
}

void Player::setCarrotsOnHunger(int value)
{
    carrotsOnHunger = value;
}

int Player::getPotatoesOnHunger() const
{
    return potatoesOnHunger;
}

void Player::setPotatoesOnHunger(int value)
{
    potatoesOnHunger = value;
}

int Player::getSpaghettiOnHunger() const
{
    return spaghettiOnHunger;
}

void Player::setSpaghettiOnHunger(int value)
{
    spaghettiOnHunger = value;
}

int Player::getEnergyDrinkOnHunger() const
{
    return energyDrinkOnHunger;
}

void Player::setEnergyDrinkOnHunger(int value)
{
    energyDrinkOnHunger = value;
}

int Player::getRiceOnEnergy() const
{
    return riceOnEnergy;
}

void Player::setRiceOnEnergy(int value)
{
    riceOnEnergy = value;
}

int Player::getBeansOnEnergy() const
{
    return beansOnEnergy;
}

void Player::setBeansOnEnergy(int value)
{
    beansOnEnergy = value;
}

int Player::getCarrotsOnEnergy() const
{
    return carrotsOnEnergy;
}

void Player::setCarrotsOnEnergy(int value)
{
    carrotsOnEnergy = value;
}

int Player::getPotatoesOnEnergy() const
{
    return potatoesOnEnergy;
}

void Player::setPotatoesOnEnergy(int value)
{
    potatoesOnEnergy = value;
}

int Player::getSpaghettiOnEnergy() const
{
    return spaghettiOnEnergy;
}

void Player::setSpaghettiOnEnergy(int value)
{
    spaghettiOnEnergy = value;
}

int Player::getEnergyDrinkOnEnergy() const
{
    return energyDrinkOnEnergy;
}

void Player::setEnergyDrinkOnEnergy(int value)
{
    energyDrinkOnEnergy = value;
}

bool Player::isSick() const
{
    return sick;
}

void Player::setSick(bool value)
{
    sick = value;
}

int Player::getHospitalOnHealth() const
{
    return hospitalOnHealth;
}

void Player::setHospitalOnHealth(int value)
{
    hospitalOnHealth = value;
}
