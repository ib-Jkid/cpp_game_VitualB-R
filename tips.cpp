#include "tips.h"
#include <QDebug>

Tips::Tips()
{
    tipNum = 0;
    tips = {
        "the new tip",
        "WELCOME TO VIRTUAL BILLIONAIRE",
        "THE BEST GAME TO PLAY AND ENJOY",
        "It's a game that has to do with our everyday life",
        "The game is all about you working make more money eat healthy be healthy and \n invest more money",
        "Take Note There is always an inflation which increases the price of goods by 1%",
        "There is also a means of making additional money apart from your daily work",
        "You can make additional money each time you spin the pie chart and you can loose money also",
        "When your health reaches 0% the avatar dies and you loose the game\n Increase your health status in the clinic",
        "The stocks are unstable commodities, They can rise and fall at anytime  so you should trade carefully",
        "When your grooming level, nutrition or energy level reaches 0,\n your avatar looses health fast",
        "buying asset can be very challenging as time goes on due to inflation",
        "Also take note whenever you commit a crime you will be arrested /n When you are arrested and found guilty you will be taken to jail /n "
        "When taken to jail, your daily feeding level decreases and you will be unable to work,"" So avoid committing any crime,"
        "beware of robbery, make use of the banks,"
        "Prices of all commodities get inflated overtime\n so invest your money wisely ",
        "hiring of body guard can be useful but ensure \nyour income is stable enough to pay them",
        "Commodites can only be purchased with cash at hand but becareful and  beware of robbers",
        "After every game cycle, your networth is recalculated",
        "you win the game when you attain a networth of $1,000,000"
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
