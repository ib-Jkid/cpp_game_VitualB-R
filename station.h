#ifndef STATION_H
#define STATION_H


class Station
{
public:
    Station();

    bool getBail(bool spent);


    double getBailAmount() const;

private:
    double bailAmount;
    double bodyGuard;
};

#endif // STATION_H
