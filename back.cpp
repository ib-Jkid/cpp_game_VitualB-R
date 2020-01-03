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
            emit on_winLotto();
        break;
        case 11:
            emit on_freeLunch();
        break;
        case 12:
            emit on_freeMedical();
            break;
        case 13:

        break;
        case 20:
            emit on_getRobbed();
        break;
        case 2:
            emit on_WinCar();
        break;
        case 14:
        break;
        case 15:

            emit on_getSued();

        break;
        case 3:
            emit on_riseStock();
        break;
        case 4:
        break;
        case 16:
            emit on_fallStock();
        break;
        case 5:
        break;
        case 17:
            emit on_heartAttack();

        break;
        case 6:
        break;
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
        break;
        case 19:
            emit on_wronglyAccused();
        break;
        case 10:
            emit on_attacked();

        break;
    }
    emit on_updateUi();
}



