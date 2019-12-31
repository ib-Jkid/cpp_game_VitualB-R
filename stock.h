#ifndef STOCK_H
#define STOCK_H

#include <stdlib.h>
#include <time.h>


class Stock
{
public:
    Stock();
    void updateStock();
    bool buyCrude(bool spent);
    bool buyGold(bool spent);
    bool buyPlatinum(bool spent);
    bool buySilver(bool spent);
    bool buyIron(bool spent);
    bool buyBronze(bool spent);

    double sellCrude();
    double sellGold();
    double sellPlatinum();
    double sellSilver();
    double sellIron();
    double sellBronze();

    double getCrudePrice() const;
    void setCrudePrice(double value);

    double getGoldPrice() const;
    void setGoldPrice(double value);

    double getPlatinumPrice() const;
    void setPlatinumPrice(double value);

    double getSilverPrice() const;
    void setSilverPrice(double value);

    double getIronPrice() const;
    void setIronPrice(double value);

    double getBronzePrice() const;
    void setBronzePrice(double value);

    int getCrudeOwned() const;


    int getGoldOwned() const;

    int getPlatinumOwned() const;


    int getSilverOwned() const;


    int getIronOwned() const;


    int getBronzeOwned() const;


    double getCrudeInitial() const;
    void setCrudeInitial(double value);

    double getGoldInitial() const;
    void setGoldInitial(double value);

    double getPlatinumInitial() const;
    void setPlatinumInitial(double value);

    double getSilverInitial() const;
    void setSilverInitial(double value);

    double getIronInitial() const;
    void setIronInitial(double value);

    double getBronzeInitial() const;
    void setBronzeInitial(double value);

    double getStockWorth();

private:
    double crudePrice;
    double goldPrice;
    double platinumPrice;
    double silverPrice;
    double ironPrice;
    double bronzePrice;

    int crudeOwned;
    int goldOwned;
    int platinumOwned;
    int silverOwned;
    int ironOwned;
    int bronzeOwned;

    double crudeInitial;
    double goldInitial;
    double platinumInitial;
    double silverInitial;
    double ironInitial;
    double bronzeInitial;
};

#endif // STOCK_H
