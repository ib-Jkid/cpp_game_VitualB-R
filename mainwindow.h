#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "assets.h"
#include "bank.h"
#include "player.h"
#include "crime.h"
#include "station.h"
#include "expenses.h"
#include "kitchen.h"
#include "stock.h"
#include "clinic.h"
#include "grooming.h"
#include "back.h"


#include <QMainWindow>
#include <iostream>
#include <QMessageBox>
#include <float.h>
#include <QtConcurrent>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void notify(QString title,QString msg);
    void updateUi();
    void doSetup(QThread &thread);
    Bank bank;
    Assets assets;
    Player player;
    Crime crime;
    Station station;
    Expenses expenses;
    Kitchen kitchen;
    Stock stock;
    Clinic clinic;
    Grooming grooming;
    QMutex mute;
    Back back;





private slots:
    void doWork();
    void on_homePageButton_clicked();

    void on_bankPageButton_clicked();

    void on_assetsPageButton_clicked();

    void on_casinoPageButton_clicked();

    void on_crimePageButton_clicked();

    void on_stationPageButton_clicked();

    void on_expensesPageButton_clicked();

    void on_jobsPageButton_clicked();

    void on_optionPageButton_clicked();

    void on_depositeButton_clicked();

    void on_fullDepositeButton_clicked();

    void on_withdrawalButton_clicked();

    void on_fullWithdrawalButton_clicked();

    void on_loanButton_clicked();

    void on_payLoanButton_clicked();

    void on_factoryBuyButton_clicked();

    void on_factorySellButton_clicked();

    void on_houseBuyButton_clicked();

    void on_houseSellButton_clicked();

    void on_refineryBuyButton_clicked();

    void on_refinerySellButton_clicked();

    void on_BankBuyButton_clicked();

    void on_BankSellButton_clicked();

    void on_collectIncomeButton_clicked();

    void on_commitTheftButton_clicked();

    void on_commitRobberyButton_clicked();

    void on_commitBankFraudButton_clicked();

    void on_getBailButton_clicked();

    void on_buyAHouse_clicked();

    void on_hireThugs_clicked();

    void on_buyACar_clicked();

    void on_hireALawyer_clicked();

    void on_hireBodyGuard_clicked();

    void on_kitchenPageButton_clicked();

    void on_consumePotatoes_clicked();

    void on_consumeCarrot_clicked();

    void on_energyDrink_clicked();

    void on_consumeBeans_clicked();

    void on_consumeSpagetti_clicked();

    void on_consumeRice_clicked();

    void on_stockPageButton_clicked();

    void on_goldBuyButton_clicked();

    void on_goldSellButton_clicked();

    void on_bronzeBuyButton_clicked();

    void on_bronzeSellButton_clicked();

    void on_oilBuyButton_clicked();

    void on_oilSellButton_clicked();

    void on_ironBuyButton_clicked();

    void on_ironSellButton_clicked();

    void on_platinumBuyButton_clicked();

    void on_platinumSellButton_clicked();

    void on_silverBuyButton_clicked();

    void on_silverSellButton_clicked();

    void on_takeAPillButton_clicked();

    void on_takeAShotButton_clicked();

    void on_payHospitalBillButton_clicked();

    void on_doCheckupButton_clicked();

    void on_HireANurseButton_clicked();

    void on_clinicPageButton_clicked();

    void on_groomingPageButton_clicked();

    void on_washHandButton_clicked();

    void on_brushTeethButton_clicked();

    void on_takeBathButton_clicked();

    void on_doLaundryButton_clicked();
    void on_collectSchoolLoanButton_clicked();

signals:
    void on_stop();
private:
    Ui::MainWindow *ui;
    void updateNoticeBoard(QString info,bool tips);
    void updateStockUi();
    void updateBankUi();
    void updateProgressUi();
    void updateAssetsUi();
    void updateCrimeUi();
    void updateStationUi();
    void updateExpensesUi();
    void updateKitchenUi();
    void updateClinicUi();
    void updateGroomingUi();
    void updateStockBoard();
    bool doAction(int value);

    void getRobbed();
    void getSued();
    void riseStock();
    void fallStock();
    void heartAttack();
    void carCrash();
    void dupped();
    void foodPoison();
    void wronglyAccused();
    void attacked();
    void runGameCycle();





};
#endif // MAINWINDOW_H
