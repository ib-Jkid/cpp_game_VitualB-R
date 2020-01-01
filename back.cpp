#include "back.h"
#include <QDebug>

Back::Back(QObject *parent) : QObject(parent)
{
    gameOver = false;
}

void Back::loop()
{
    while(!gameOver) {
        QThread::currentThread()->sleep(10);
        emit on_updateNoticeBoard(tips.getTips(),true);
        QThread::currentThread()->sleep(10);
        emit on_updateNoticeBoard(tips.getTips(),true);
        QThread::currentThread()->sleep(10);
        emit on_updateNoticeBoard(tips.getTips(),true);
        QThread::currentThread()->sleep(10);
       // emit on_updateNoticeBoard(tips.getTips(),true);
        runChance();
        QThread::currentThread()->sleep(10);
        emit on_updateNoticeBoard(tips.getTips(),true);
        QThread::currentThread()->sleep(10);
        //emit on_updateNoticeBoard(tips.getTips(),true);
        runGameCycle();
    }
}

void Back::stop() {
    gameOver = true;
}

void Back::runGameCycle() {

    emit on_runGameCycle();
    emit on_updateUi();
}
void Back::runChance()
{

    int random = rand() % 20 + 1;
    switch(random) {
        case 1:
        case 11:
        case 12:
        case 13:
        case 20:
            emit on_getRobbed();
        break;
        case 2:
        case 14:
        case 15:

            emit on_getSued();

        break;
        case 3:
            emit on_riseStock();
        break;
        case 4:
        case 16:
            emit on_fallStock();
        break;
        case 5:
        case 17:
            emit on_heartAttack();

        break;
        case 6:
        case 18:
            emit on_carCrash();
        break;
        case 7:
            emit on_dupped();
        break;
        case 8:
            emit on_foodPoison();

        break;
        case 9:
        case 19:
            emit on_wronglyAccused();
        break;
        case 10:
            emit on_attacked();

        break;
    }
    emit on_updateUi();
}



