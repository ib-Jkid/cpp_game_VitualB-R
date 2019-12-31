#include "stock.h"

Stock::Stock()
{
    crudePrice = 50.0;
    goldPrice = 100.0;
    platinumPrice = 70.0;
    silverPrice = 60.0;
    ironPrice = 30.0;
    bronzePrice = 40.0;

    crudeOwned = 0;
    goldOwned = 0;
    platinumOwned = 0;
    silverOwned = 0;
    ironOwned = 0;
    bronzeOwned = 0;

    crudeInitial = 0;
    goldInitial = 0;
    platinumInitial = 0;
    silverInitial = 0;
    ironInitial = 0;
    bronzeInitial = 0;

    srand (time(NULL));

}

double Stock::getStockWorth() {
    return (
        (crudeOwned * crudePrice)+
        (silverOwned * silverPrice)+
        (platinumOwned * platinumPrice)+
         (bronzeOwned * bronzePrice)+
         (ironOwned * ironPrice)+
        (goldOwned * goldPrice)

    );
}
double newPrice(double initailPrice) {
    int percent = rand() % 100 + 1;
    int coin = rand() % 2;
    if(coin == 0) {
        initailPrice += (initailPrice /100 * percent);
        return initailPrice;
    }else {
        initailPrice -= (initailPrice /100 * percent);
        return initailPrice;
    }
}

void Stock::updateStock() {
    crudeInitial = crudePrice;
    goldInitial = goldPrice;
    platinumInitial = platinumPrice;
    silverInitial = silverPrice;
    ironInitial = ironPrice;
    bronzeInitial = bronzePrice;

    crudePrice = newPrice(crudeInitial);
    goldPrice = newPrice(goldInitial);
    platinumPrice = newPrice(platinumInitial);
    silverPrice = newPrice(silverInitial);
    ironPrice = newPrice(ironInitial);
    bronzePrice = newPrice(bronzeInitial);



}



bool Stock::buyCrude(bool spent)
{
    if(spent) {
        crudeOwned++;
        crudePrice += (crudePrice * 0.3);
        return true;
    }
    return false;
}

bool Stock::buyGold(bool spent)
{
    if(spent) {
        goldOwned++;
        goldPrice += (goldPrice * 0.3);
        return true;
    }
    return false;
}

bool Stock::buyPlatinum(bool spent)
{
    if(spent) {
        platinumOwned++;
        platinumPrice += (platinumPrice * 0.3);
        return true;
    }
    return false;
}

bool Stock::buySilver(bool spent)
{
    if(spent) {
        silverOwned++;
        silverPrice += (silverPrice * 0.3);
        return true;
    }
    return false;
}

bool Stock::buyIron(bool spent)
{
    if(spent) {
        ironOwned++;
        ironPrice += (ironPrice * 0.3);
        return true;
    }
    return false;
}

bool Stock::buyBronze(bool spent)
{
    if(spent) {
        bronzeOwned++;
        bronzePrice += (bronzePrice * 0.3);
        return true;
    }
    return false;
}

double Stock::sellCrude()
{
    if(crudeOwned > 0) {
        crudeOwned--;
        double price = crudePrice;
        crudePrice -= (crudePrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::sellGold()
{
    if(goldOwned > 0) {
        goldOwned--;
        double price = goldPrice;
        goldPrice -= (goldPrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::sellPlatinum()
{
    if(platinumOwned > 0) {
        platinumOwned--;
        double price = platinumPrice;
        platinumPrice -= (platinumPrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::sellSilver()
{
    if(silverOwned > 0) {
        silverOwned--;
        double price = silverPrice;
        silverPrice -= (silverPrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::sellIron()
{
    if(ironOwned > 0) {
        ironOwned--;
        double price = ironPrice;
        ironPrice -= (ironPrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::sellBronze()
{
    if(bronzeOwned > 0) {
        bronzeOwned--;
        double price = bronzePrice;
        bronzePrice -= (bronzePrice * 0.6);
        return price;
    }
    return 0.0;
}

double Stock::getCrudePrice() const
{
    return crudePrice;
}

void Stock::setCrudePrice(double value)
{
    crudePrice = value;
}

double Stock::getGoldPrice() const
{
    return goldPrice;
}

void Stock::setGoldPrice(double value)
{
    goldPrice = value;
}

double Stock::getPlatinumPrice() const
{
    return platinumPrice;
}

void Stock::setPlatinumPrice(double value)
{
    platinumPrice = value;
}

double Stock::getSilverPrice() const
{
    return silverPrice;
}

void Stock::setSilverPrice(double value)
{
    silverPrice = value;
}

double Stock::getIronPrice() const
{
    return ironPrice;
}

void Stock::setIronPrice(double value)
{
    ironPrice = value;
}

double Stock::getBronzePrice() const
{
    return bronzePrice;
}

void Stock::setBronzePrice(double value)
{
    bronzePrice = value;
}

int Stock::getCrudeOwned() const
{
    return crudeOwned;
}


int Stock::getGoldOwned() const
{
    return goldOwned;
}

int Stock::getPlatinumOwned() const
{
    return platinumOwned;
}


int Stock::getSilverOwned() const
{
    return silverOwned;
}



int Stock::getIronOwned() const
{
    return ironOwned;
}


int Stock::getBronzeOwned() const
{
    return bronzeOwned;
}

double Stock::getCrudeInitial() const
{
    return crudeInitial;
}

void Stock::setCrudeInitial(double value)
{
    crudeInitial = value;
}

double Stock::getGoldInitial() const
{
    return goldInitial;
}

void Stock::setGoldInitial(double value)
{
    goldInitial = value;
}

double Stock::getPlatinumInitial() const
{
    return platinumInitial;
}

void Stock::setPlatinumInitial(double value)
{
    platinumInitial = value;
}

double Stock::getSilverInitial() const
{
    return silverInitial;
}

void Stock::setSilverInitial(double value)
{
    silverInitial = value;
}

double Stock::getIronInitial() const
{
    return ironInitial;
}

void Stock::setIronInitial(double value)
{
    ironInitial = value;
}

double Stock::getBronzeInitial() const
{
    return bronzeInitial;
}

void Stock::setBronzeInitial(double value)
{
    bronzeInitial = value;
}
