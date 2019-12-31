#include "tips.h"

Tips::Tips()
{
    tipNum = 0;
    tips = {
        "When you health reaches 0% the avatar dies and you loose the game\n Increase you health status in the clinic",
        "The stocks are unstable commodities and can rise and fall at anytime trade carefully",
        "When your grooming level, nutrition or energy level reaches 0,\n your avatar looses health fast",
        "buying asset can be very chalenging as time goes due to inflation",
        "beware of robbery make use of the banks",
        "Prices of all commodities get inflated overtime\n so invest money do not keep the idle",
        "hiring of body guard can be usefull but ensure \nyour income is stable enough to pay them",
        "Commodites can only be purchased with cash at hand but beware of robbers",
        "After every game cycle, you networth is recalculated",
        "you win the came when you attain a networth of $1,000,000"
    };
}

QString Tips::getTips()
{
    tipNum++;
    if(tipNum == tips.length()) {
        tipNum = 0;
    }
    return tips[tipNum];
}
