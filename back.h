#ifndef BACK_H
#define BACK_H

#include <QObject>
#include <QThread>

#include "tips.h"

class Back : public QObject
{
    Q_OBJECT
public:
    explicit Back(QObject *parent = nullptr);
    void loop();
    void stop();
    Tips tips;

signals:
    void on_updateNoticeBoard(QString info,bool tips = false);
    void on_getRobbed();
    void on_gameCycle();
    void on_getSued();
    void on_riseStock();
    void on_fallStock();
    void on_heartAttack();
    void on_carCrash();
    void on_dupped();
    void on_foodPoison();
    void on_wronglyAccused();
    void on_attacked();
    void on_updateUi();
    void on_runGameCycle();
    void on_winLotto();
    void on_freeLunch();
    void on_freeMedical();
    void on_WinCar();
private:
    void runChance();
    bool gameOver;
    void runGameCycle();

};

#endif // BACK_H
