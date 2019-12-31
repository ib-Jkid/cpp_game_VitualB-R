#include "station.h"

Station::Station()
{
    bailAmount = 100000.0;

}

bool Station::getBail(bool spent)
{
    if(spent) {

        bailAmount += 5000.0;
        return true;
    }
    return false;
}

double Station::getBailAmount() const
{
    return bailAmount;
}
