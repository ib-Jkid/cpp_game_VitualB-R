#include "station.h"

Station::Station()
{
    bailAmount = 1000.0;

}

bool Station::getBail(bool spent)
{
    if(spent) {

        bailAmount += 100;
        return true;
    }
    return false;
}

double Station::getBailAmount() const
{
    return bailAmount;
}
