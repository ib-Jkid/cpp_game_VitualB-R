#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateUi();
    connect(&back,&Back::on_updateNoticeBoard,this,&MainWindow::updateNoticeBoard);
    connect(&back,&Back::on_getRobbed,this,&MainWindow::getRobbed);
    connect(&back,&Back::on_getSued,this,&MainWindow::getSued);
    connect(&back,&Back::on_riseStock,this,&MainWindow::riseStock);
    connect(&back,&Back::on_fallStock,this,&MainWindow::fallStock);
    connect(&back,&Back::on_heartAttack,this,&MainWindow::heartAttack);
    connect(&back,&Back::on_carCrash,this,&MainWindow::carCrash);
    connect(&back,&Back::on_dupped,this,&MainWindow::dupped);
    connect(&back,&Back::on_foodPoison,this,&MainWindow::foodPoison);
    connect(&back,&Back::on_wronglyAccused,this,&MainWindow::wronglyAccused);
    connect(&back,&Back::on_attacked,this,&MainWindow::attacked);
    connect(&back,&Back::on_updateUi,this,&MainWindow::updateUi);
    connect(&back,&Back::on_runGameCycle,this,&MainWindow::runGameCycle);
    connect(this,&MainWindow::on_stop,&back,&Back::stop);
    QFuture<void> test = QtConcurrent::run(&this->back,&Back::loop);

    connect(&job,&Job::on_payTuitionFee,this,&MainWindow::payTutionFee);
    connect(this,&MainWindow::tutionFeePaid,&job,&Job::tutionFeePaid);
    connect(&job,&Job::on_paySalary,this,&MainWindow::paySalary);




}



MainWindow::~MainWindow()
{
    delete ui;
    emit on_stop();


}

double MainWindow::getCalculatedNetWorth() {
   return (assets.getTotalAssetWorth()
           + bank.getFinancialSummary()
           + stock.getStockWorth());
}

void MainWindow::runGameCycle() {

    job.gameCycle();
    if(job.isWorking()) {
        player.setEnergy(player.getEnergy() - 50);
        if(job.getWorkingAsDoctor()) player.setHealthStatus(player.getHealthStatus() - 20);
        if(job.getWorkingAslabourer()) player.setHealthStatus(player.getHealthStatus() - 50);
        if(job.getWorkingAsBrickLayer()) player.setHealthStatus(player.getHealthStatus() - 40);
        if(job.getWorkingAsPoliceOfficer()) player.setHealthStatus(player.getHealthStatus() - 30);
    }
    bank.loose(expenses.getExpenses());
    assets.gameCycle(0.01);
    bank.gameCycle(0.01);
    clinic.gameCycle(0.01);
    expenses.gameCycle(0.01);
    grooming.gameCycle(0.01);
    kitchen.gameCycle(0.01);
    player.gameCycle();
    stock.updateStock();

    if(player.isDead()) {
        QMessageBox::critical(this,"Game Over","you died!!");
        emit on_stop();
        qDebug() << "game Over" ;

        return ;
    }
    if( getCalculatedNetWorth() < 0){
        QMessageBox::critical(this,"Game Over","You are broke");
        emit on_stop();

        return ;
    }
    if(getCalculatedNetWorth() > 1000000) {
        QMessageBox::information(this,"You Won","You net worth is over $1,000,000");
        emit on_stop();



    }
    qDebug() << getCalculatedNetWorth(); ;

}

void MainWindow::payTutionFee(double fee)
{
    if((bank.getMoneyAtHand() + bank.getAccountBalance()) > fee) {
        if(bank.loose(fee)) {
            emit tutionFeePaid(true);
        }else {
            emit tutionFeePaid(false);
        }
    }else {
        emit tutionFeePaid(false);
    }
}

void MainWindow::paySalary(double salary)
{
    if(bank.recieveEarnings(salary)) {
        updateNoticeBoard("Salary of $" + QString::number(salary)+ "has been recieved",false);
    }
}


void MainWindow::notify(QString title, QString msg)
{
    QString color[] = {"red", "blue", "brown","white"};
    int i = rand() % 5;
    ui->gameUpdateBoard->setHtml("<b>"+title+":</b>"+"<font color='"+color[i]+"'> "+ msg + "</font>");
}
bool MainWindow::doAction(int value) {
    int ran = rand()% 5+1;
    if(ran > value) {
        return true;
    }
    return false;


}
void MainWindow::getRobbed() {
    int value = 0;
    if(expenses.hasCar()) {
        value++;
    }
    if(expenses.hasBodyGuard()) {
        value++;
    }
    if(expenses.hasThugs()) {
        value++;
    }
    if(doAction(value)) {
        if(bank.getMoneyAtHand() > 0) {
            bank.setMoneyAtHand(0.0);
            notify("ROBBERY","You have been robbed keep money in the bank");
        }else {
            player.setHealthStatus(player.getHealthStatus()-50);
            player.setEnergy(player.getEnergy()-50);
            notify("ROBBERY","They Shoot you because you had no money \n go get treated");
        }

    }else {
        notify("ROBBERY","You were saved from a robbery");
    }
}

void MainWindow::getSued() {
    int value = 0;
    if(expenses.hasLawyer()) {
        value += 4;
    }
    if(doAction(value)) {
        bank.loose(bank.getAccountBalance() /2);
        notify("LAW SUIT","You lost $"+QString::number(bank.getAccountBalance() /2)+" hire a lawyer to win cases");
    }else{
        bank.earn(100.0);
        notify("LAW SUIT","You won $1000 in a law suit");
    }
}

void MainWindow::riseStock() {
    stock.setGoldPrice(stock.getGoldPrice() * 2);
    stock.setPlatinumPrice(stock.getPlatinumPrice() * 2);
    stock.setIronPrice(stock.getIronPrice() * 2);
    stock.setBronzePrice(stock.getBronzePrice() * 2);
    stock.setCrudePrice(stock.getCrudePrice() * 2);
    stock.setSilverPrice(stock.getSilverPrice() * 2);
    notify("STOCKS","All commodities risen by a 100%");
}

void MainWindow::fallStock() {
    stock.setGoldPrice(stock.getGoldPrice() / 2);
    stock.setPlatinumPrice(stock.getPlatinumPrice() / 2);
    stock.setIronPrice(stock.getIronPrice() / 2);
    stock.setBronzePrice(stock.getBronzePrice() / 2);
    stock.setCrudePrice(stock.getCrudePrice() / 2);
    stock.setSilverPrice(stock.getSilverPrice() / 2);
    notify("STOCKS","All commodities fallen by a 50%");
}

void MainWindow::heartAttack() {
    int value = 0;
    if(expenses.hasNurse()) {
        value += 3;
    }
    if(doAction(value)) {
        player.setHealthStatus(player.getHealthStatus() - 30);
        player.setEnergy(player.getEnergy()-50);
        notify("HEART ATTACK","You have been rushed to the clinic");
    }else {
        notify("HEART ATTACK","Your nurse came to your rescure");
    }
}

void MainWindow::carCrash() {
    player.setHealthStatus(player.getHealthStatus()-50);
    player.setEnergy(player.getEnergy()-30);
    notify("MOTOR CRASH","You were involved in an accident");
}

void MainWindow::dupped() {
    bank.loose(50);
    notify("DUPPED","You get dupped by your business associates and lost $50");
}

void MainWindow::foodPoison() {
    if(expenses.hasNurse()){
        notify("Food Poisoning","You nearly died but you nurse saved you");
    }else{
        player.setHealthStatus(player.getHealthStatus() - 20);
        player.setEnergy(player.getEnergy()-20);
        notify("Food Poisoning","Get a nurse to prevent being sick");
    }
}

void MainWindow::wronglyAccused() {
    player.setFree(false);
    notify("Wrongly Accused","You have been sent to jail for a crime you didn't commit");
}

void MainWindow::attacked() {
    if(expenses.hasBodyGuard()) {
        notify("Attacked","You were attacked and your body guard took a bullet for you");
    }else {
        player.setHealthStatus(player.getHealthStatus()-10);
        player.setEnergy(player.getEnergy() - 50);
        notify("Attacked","You were shot in the leg by your attackers go treat Yourself");
    }
}

//Navigation Code Start
void MainWindow::on_homePageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}

void MainWindow::on_bankPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->bankPage);
}

void MainWindow::on_assetsPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->assetsPage);
}

void MainWindow::on_casinoPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->casinoPage);
}

void MainWindow::on_crimePageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->crimePage);
}

void MainWindow::on_stationPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stationPage);
}

void MainWindow::on_expensesPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->expensesPage);
}

void MainWindow::on_jobsPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->jobsPage);
}

void MainWindow::on_optionPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->optionPage);
}
void MainWindow::on_kitchenPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->kitchenPage);
}

void MainWindow::on_stockPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stockPage);
}

void MainWindow::on_clinicPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->clinicPage);
}


void MainWindow::on_groomingPageButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->groomingPage);
}
//Navigation Code Ends
/**************************************************
 *
 * Update UI
 *
 * */

void MainWindow::updateIncomeStatementUi()  {
    ui->activeIncomeLabel->setText("$"+QString::number(job.getCurrentIncome())+"/C");
    ui->passiveIncomeLabel->setText("$"+QString::number(assets.getTotalIncome())+"/C");

    ui->totalExpensesLabel->setText("$"+QString::number(expenses.getExpenses())+"/C");

    ui->stockWorthLabel->setText("$"+QString::number(stock.getStockWorth()) +"/C");
    ui->cashFlowLabel->setText("$"+QString::number(bank.getFinancialSummary()+bank.getDept()));
    ui->deptLabel->setText("$"+QString::number(bank.getDept() + bank.getSchoolLoan()));
    ui->NetWorthLabel->setText("$"+QString::number(getCalculatedNetWorth()));
}
void MainWindow::updateNoticeBoard(QString info,bool tips = false) {
    if(tips) {
        QString prefix("Tips: ");
        ui->noticeBoard->setHtml("<b>"+prefix+"</b>"+"<font color='blue'>"+ info + "</font>");

    }
    else{
        QString prefix("Notice: ");
        ui->noticeBoard->setHtml("<b>"+prefix+"</b>"+"<font color='brown'>" + info + "</font>");

    }
}

void MainWindow::updateStockBoard() {
    ui->goldStatLabel->setText("$" + QString::number(stock.getGoldPrice()-stock.getGoldInitial()));
    ui->silverStatLabel->setText("$" + QString::number(stock.getSilverPrice()-stock.getSilverInitial()));
    ui->ironStatLabel->setText("$" + QString::number(stock.getIronPrice()-stock.getIronInitial()));
    ui->crudeStatLabel->setText("$" + QString::number(stock.getCrudePrice()-stock.getCrudeInitial()));
    ui->bronzeStatLabel->setText("$" + QString::number(stock.getBronzePrice()-stock.getBronzeInitial()));
    ui->platinumStatLabel->setText("$" + QString::number(stock.getPlatinumPrice()-stock.getPlatinumInitial()));
}

void MainWindow::updateJobUi()
{
    if(job.getLearningDoctor()){
        ui->startDoctorsTraining->setText("Studying");
    }else if(job.getDoctorSkillProgress() >= 100){
        ui->startDoctorsTraining->setText("Certified");
        ui->startDoctorsTraining->setDisabled(true);
    }else{
        ui->startDoctorsTraining->setText("Get Cert");
    }

    if(job.getApplyingDoctorJob()) {
        ui->applyDoctorsJob->setText("Applying");
    }else if(job.getWorkingAsDoctor()) {
        ui->applyDoctorsJob->setText("Working");
    }else {
        ui->applyDoctorsJob->setText("Apply");
    }


    if(job.getLearningPoliceOfficer())
    {
        ui->startPoliceOfficerTraining->setText("Training");
    }else if(job.getPoliceOfficerSkillProgress() >= 100){
        ui->startPoliceOfficerTraining->setText("Trained");
        ui->startPoliceOfficerTraining->setDisabled(true);
    }else{
        ui->startPoliceOfficerTraining->setText("Do Training");
    }

    if(job.getApplyingPoliceOfficer()) {
        ui->applyPoliceOfficerJob->setText("Applying");
    }else if(job.getWorkingAsPoliceOfficer()) {
        ui->applyPoliceOfficerJob->setText("Working");
    }else {
        ui->applyPoliceOfficerJob->setText("Apply");
    }

    if(job.getLearningBrickLaying())
    {
        ui->learnBricklayerJob->setText("learning");

    }else if(job.getBrickLayingSkillProgress() >= 100){
        ui->learnBricklayerJob->setText("learnt");
        ui->learnBricklayerJob->setDisabled(true);
    }else{
        ui->learnBricklayerJob->setText("learn");
    }

    if(job.getApplyingBrickLaying()) {
        ui->applyBrickLayerJob->setText("Applying");
    }else if(job.getWorkingAsBrickLayer()) {
        ui->applyBrickLayerJob->setText("Working");
    }else {
         ui->applyBrickLayerJob->setText("Apply");
    }


    if(job.getApplyingLabourer()){
        ui->applyingLabourerJob->setText("Applying");
    }else if(job.getWorkingAslabourer()){
        ui->applyingLabourerJob->setText("Working");
    }else {
        ui->applyingLabourerJob->setText("Apply");
    }
    ui->brickLayingProgress->setText(QString::number(job.getBrickLayingSkillProgress()) + "%");
    ui->policeTrainingProgress->setText(QString::number(job.getPoliceOfficerSkillProgress()) + "%");
    ui->medicalTrainingProgress->setText(QString::number(job.getDoctorSkillProgress()) + "%");
}

void MainWindow::updateGroomingUi() {
    ui->takeBathButton->setText("$"+QString::number(grooming.getBathCost()));
    ui->doLaundryButton->setText("$"+QString::number(grooming.getLaundryCost()));
    ui->brushTeethButton->setText("$"+QString::number(grooming.getBrushCost()));
    ui->washHandButton->setText("$"+QString::number(grooming.getWashHandCost()));
}
void MainWindow::updateBankUi() {
    //Bank UI
    ui->bankAccountBalance->setText("$"+QString::number((int)bank.getAccountBalance()));
    ui->moneyAtHand->setText("$"+QString::number((int)bank.getMoneyAtHand()));
    ui->outstandingDept->setText("$"+QString::number((int)bank.getDept()));
    ui->loanLimitLabel->setText("$"+QString::number((int)assets.getLoanLimit()));
    ui->schoolLoanLimit->setText("$"+QString::number((int)bank.getSchoolLoanLimit()));
    if(bank.getSchoolLoan() > 0.0) {
        ui->collectSchoolLoanButton->setText("No Loan");
    }
    else{
        ui->collectSchoolLoanButton->setText("Collect Loan");
    }
    //End Bank UI
}
void MainWindow::updateStockUi() {
    ui->goldOwnedLabel->setText("Own :"+QString::number(stock.getGoldOwned()));
    ui->oilOwnedLabel->setText("Own :"+QString::number(stock.getCrudeOwned()));
    ui->silverOwnedLabel->setText("Own :"+QString::number(stock.getSilverOwned()));
    ui->platiniumOwnedLabel->setText("Own :"+QString::number(stock.getPlatinumOwned()));
    ui->bronzeOwnedLabel->setText("Own :"+QString::number(stock.getBronzeOwned()));
    ui->ironOwnedLabel->setText("Own :"+QString::number(stock.getIronOwned()));

    ui->goldPriceLabel->setText("$"+QString::number(stock.getGoldPrice()));
    ui->oilPriceLabel->setText("$"+QString::number(stock.getCrudePrice()));
    ui->silverPriceLabel->setText("$"+QString::number(stock.getSilverPrice()));
    ui->platiniumPriceLabel->setText("$"+QString::number(stock.getPlatinumPrice()));
    ui->bronzePriceLabel->setText("$"+QString::number(stock.getBronzePrice()));
    ui->ironPriceLabel->setText("$"+QString::number(stock.getIronPrice()));




    updateBankUi();
}
void MainWindow::updateProgressUi() {
    ui->foodStatusBar->setValue(player.getStarvationLevel());
    ui->energyStatusBar->setValue(player.getEnergy());
    ui->healthStatusBar->setValue(player.getHealthStatus());
    ui->groomStatusBar->setValue(player.getGroomingLevel());
}

void MainWindow::updateAssetsUi() {

    //Asset Ui
    ui->factoryOwnedLabel->setText(QString::number(assets.getFactoryOwned()));
    ui->factoryIncome->setText("$"+QString::number((int)assets.getFactoryIncome()));
    ui->factoryCostLabel->setText("$"+QString::number((int)assets.getFactoryCost()));

    ui->houseOwnedLabel->setText(QString::number(assets.getHouseOwned()));
    ui->houseIncomeLabel->setText("$" + QString::number((int)assets.getHouseIncome()));
    ui->houseCostLabel->setText("$" + QString::number((int)assets.getHouseCost()));

    ui->bankOwnedLabel->setText(QString::number((int)assets.getBankOwned()));
    ui->bankIncomeLabel->setText("$"+QString::number((int)assets.getBankIncome()));
    ui->bankCostLabel->setText("$"+QString::number((int)assets.getBankCost()));

    ui->refineryOwnedLabel->setText(QString::number(assets.getRefineryOwned()));
    ui->refineryIncomeLabel->setText("$"+QString::number((int)assets.getRefineryIncome()));
    ui->refineryCostLabel->setText("$"+QString::number((int)assets.getRefineryCost()));

    ui->accummulatedIncome->setText("$"+QString::number((int)assets.getAccumulatedIncome()));
    ui->incomePerCycleLabel->setText("$"+QString::number((int)assets.getIncomePerCycle()));
    ui->accumulatedIncomeProgressBar->setValue(assets.getProgress());
    //Asset Ui ends
}

void MainWindow::updateCrimeUi() {
    //crime Ui Start
    ui->robberySuccessRate->setText(QString::number(crime.getRobberyChance())+"%");
    ui->theftSuccessRate->setText(QString::number(crime.getTheftChance())+"%");
    ui->bankFraudSuccessRate->setText(QString::number(crime.getBankChance())+"%");
    if(player.isFree()) {
        ui->freedomStatus->setText("FREE");
    }else {
        ui->freedomStatus->setText("ARRESTED");
    }
}

void MainWindow::updateStationUi() {
    //station ui

    ui->bailCostLabel->setText("Get Bail At $"+QString::number((int)station.getBailAmount()));
    if(expenses.hasBodyGuard()) {
        ui->hireBodyGuard->setText("Fire");
    }else {
        ui->hireBodyGuard->setText("Hire");
    }

}

void MainWindow::updateExpensesUi() {


    //Expenses Ui
    if(expenses.hasHouse() && !expenses.getMortgaging() && !expenses.getRenting())  {
        ui->buyAHouse->setText("Sell");
    }else {
        ui->buyAHouse->setText("$"+QString::number((int) expenses.getHouseCost()));
    }

    if(expenses.hasThugs()) {
        ui->hireThugs->setText("FIRE");
    }else {
        ui->hireThugs->setText("HIRE");
    }

    if(expenses.hasCar()) {
        ui->buyACar->setText("sell");
    }else {
        ui->buyACar->setText("$"+QString::number((int) expenses.getCarCost()));
    }

    if(expenses.hasLawyer()) {
        ui->hireALawyer->setText("FIRE");
    }else {
        ui->hireALawyer->setText("HIRE");
    }
    if(expenses.getRenting()) {
        ui->rentAHouse->setText("Renting");
    }else {
        ui->rentAHouse->setText("Rent");
    }

}

void MainWindow::updateKitchenUi() {
    //Kitchen Ui
    ui->potatoCostLabel->setText("$"+QString::number(kitchen.getPotatoCost()));
    ui->riceCostLabel->setText("$"+QString::number(kitchen.getRiceCost()));
    ui->carrotCostLabel->setText("$"+QString::number(kitchen.getCarrotCost()));
    ui->energyDrinkLabel->setText("S"+QString::number(kitchen.getEnergyDrinkCost()));
    ui->beansCostLabel->setText("$"+QString::number(kitchen.getBeansCost()));
    ui->spagettiCostLabel->setText("$"+QString::number(kitchen.getSpagettiCost()));

}

void MainWindow::updateClinicUi(){
    ui->pillCostLabel->setText("$"+QString::number(clinic.getPillCost()));
    ui->injectionCostLabel->setText("$"+QString::number(clinic.getInjectionCost()));
    ui->checkupBillLabel->setText("$"+QString::number(clinic.getCheckupBill()));
    ui->hospitalBillLabel->setText("$"+QString::number(clinic.getHospitalBill()));
    if(expenses.hasNurse()) {
        ui->HireANurseButton->setText("Fire Nurse");
    }else {
        ui->HireANurseButton->setText("Hire Nurse");
    }

}


void MainWindow::updateUi()
{
    updateProgressUi();
    updateStockUi();
    updateBankUi();
    updateProgressUi();
    updateAssetsUi();
    updateCrimeUi();
    updateStationUi();
    updateExpensesUi();
    updateKitchenUi();
    updateClinicUi();
    updateStockBoard();
    updateGroomingUi();
    updateJobUi();
    updateIncomeStatementUi();

}

void MainWindow::doSetup(QThread &thread)
{
    connect(&thread,SIGNAL(started()),this,SLOT(doWork()));

}

void MainWindow::doWork()
{
    do {
        updateNoticeBoard("thjjkkj");
        bank.setMoneyAtHand(bank.getMoneyAtHand() + 1);
        updateUi();
        std::cout << "theade";
        QThread::currentThread()->sleep(100);
    }while(true);




}


//Bank Controls
void MainWindow::on_depositeButton_clicked()
{
    double depositeAmount;
    QString text = ui->depositeComboBox->currentText();
    if(text == "$50") {
        depositeAmount = 50.0;
    }else if(text == "$100") {
        depositeAmount = 100.0;
    }else if(text == "$150") {
        depositeAmount = 150.0;
    }else if(text == "$200") {
        depositeAmount = 200.0;
    }else if(text == "$250") {
        depositeAmount = 250.0;
    }else if(text == "$500") {
        depositeAmount = 500.0;
    }else if(text == "$1,000") {
        depositeAmount = 1000.0;
    }else {
        depositeAmount = 0.0;
    }
    if(bank.deposite(depositeAmount)) {
        updateNoticeBoard("Your deposite was successfull");

    }else {
        updateNoticeBoard("Insuficient Fund");
    }
    updateBankUi();

}

void MainWindow::on_fullDepositeButton_clicked()
{
    if(bank.deposite(bank.getMoneyAtHand()-bank.getCharges())) {
        updateNoticeBoard("Your deposite was successfull");

    }else {
        updateNoticeBoard("Insuficient Fund");
    }
    updateBankUi();
}



void MainWindow::on_withdrawalButton_clicked()
{
    double withdrawAmount= 0.0;
    QString text = ui->withdrawalComboBox->currentText();
    if(text == "$50") {
        withdrawAmount = 50.0;
    }else if(text == "$100") {
        withdrawAmount = 100.0;
    }else if(text == "$150") {
        withdrawAmount = 150.0;
    }else if(text == "$200") {
        withdrawAmount = 200.0;
    }else if(text == "$250") {
        withdrawAmount = 250.0;
    }else if(text == "$500") {
        withdrawAmount = 500.0;
    }else if(text == "$1,000") {
        withdrawAmount = 1000.0;
    }
    if(bank.withdraw(withdrawAmount)) {
        updateNoticeBoard("Your withdrawal was successfull");
    }else {
        updateNoticeBoard("Insuficient Fund");
    }
    updateBankUi();
}
void MainWindow::on_fullWithdrawalButton_clicked()
{
    if(bank.withdraw(bank.getAccountBalance()-bank.getCharges())) {
        updateNoticeBoard("Your withdrawal was successfull");
    }else {
        updateNoticeBoard("Insuficient Fund");
    }
    updateBankUi();
}
void MainWindow::on_loanButton_clicked()
{
    double loanAmount = 0.0;
    QString text = ui->loanComboBox->currentText();
    if(text == "$5,000") {
        loanAmount = 5000.0;
    }else if(text == "$10,000") {
        loanAmount = 10000.0;
    }else if(text == "$15,000") {
        loanAmount = 15000.0;
    }else if(text == "$20,000") {
        loanAmount = 20000.0;
    }else if(text == "$25,000") {
        loanAmount = 25000.0;
    }else if(text == "$50,000") {
        loanAmount = 50000.0;
    }else if(text == "$100,000") {
        loanAmount = 100000.0;
    }

    if(bank.processLoan(loanAmount,assets.getLoanLimit())) {
        updateNoticeBoard("Your loan has been proccesed");
    }else {
        updateNoticeBoard("You are not entitles to this loan Amount");
    }
    updateBankUi();
}
void MainWindow::on_payLoanButton_clicked()
{
    if(bank.payDept()) {
        updateNoticeBoard("You loan has been payed");
    }else {
        updateNoticeBoard("You loan payment was unsuccessfull");
    }
    updateBankUi();
}
//End Bank Controls
//Assets Control
void MainWindow::on_factoryBuyButton_clicked()
{
    QString text = ui->factoryComboBox->currentText();

    if(bank.spend(assets.buyFactory(text.toInt(),bank.getMoneyAtHand()))) {
        updateNoticeBoard("You have aquired the asset successfully");
    }else {
        updateNoticeBoard("Your Asset Purchased Failed, please ensure you have sufficient cash");
    }
    updateAssetsUi();
    updateBankUi();

}

void MainWindow::on_factorySellButton_clicked()
{
    QString text = ui->factoryComboBox->currentText();
    if(bank.earn(assets.sellFactory(text.toInt()))) {
        updateNoticeBoard("Asset Sold");
    }else {
        updateNoticeBoard("Failed!!, ensure you have asset to sell");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_houseBuyButton_clicked()
{
    QString text = ui->houseComboBox->currentText();
    if(bank.spend(assets.buyHouse(text.toInt(),bank.getMoneyAtHand()))){
        updateNoticeBoard("You have aquired the asset successfully");
    }else {
        updateNoticeBoard("Your Asset Purchased Failed, please ensure you have sufficient cash");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_houseSellButton_clicked()
{
    QString text = ui->houseComboBox->currentText();
    if(bank.earn(assets.sellHouse(text.toInt()))) {
        updateNoticeBoard("Asset Sold");
    }else {
        updateNoticeBoard("Failed!!, you have no asset to sell");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_refineryBuyButton_clicked()
{
    QString text = ui->refineryComboBox->currentText();
    if(bank.spend(assets.buyRefinery(text.toInt(),bank.getMoneyAtHand()))){
        updateNoticeBoard("You have aquired the asset successfully");
    }else {
        updateNoticeBoard("Your Asset Purchased Failed, insufficient cash");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_refinerySellButton_clicked()
{
    QString text = ui->refineryComboBox->currentText();
    if(bank.earn(assets.sellRefinery(text.toInt()))) {
        updateNoticeBoard("Asset Sold");
    }else {
        updateNoticeBoard("Failed!!, ensure you have asset to sell");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_BankBuyButton_clicked()
{
    QString text = ui->bankAssetComboBox->currentText();
    if(bank.spend(assets.buyBank(text.toInt(),bank.getMoneyAtHand()))){
        updateNoticeBoard("You have aquired the asset successfully");
    }else {
        updateNoticeBoard("Your Asset Purchased Failed, please ensure you have sufficient cash");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_BankSellButton_clicked()
{
    QString text = ui->bankAssetComboBox->currentText();
    if(bank.earn(assets.sellBank(text.toInt()))) {
        updateNoticeBoard("Asset Sold");
    }else {
        updateNoticeBoard("Failed!!, ensure you have asset to sell");
    }
    updateAssetsUi();
    updateBankUi();
}

void MainWindow::on_collectIncomeButton_clicked()
{
    if(bank.earn(assets.collectIncome())) {
        updateNoticeBoard("Income Collected");
    }else {
        updateNoticeBoard("Failed!! no income to collect");
    }
    updateAssetsUi();
    updateBankUi();
}
//Assets control ends

//Crime Control Start

void MainWindow::on_commitTheftButton_clicked()
{
    if(player.isFree() && !player.isSick()) {
        if(bank.earn(crime.commitTheft())) {
            updateNoticeBoard("You are getting better at this");
        }else {
            player.setFree(false);
            updateNoticeBoard("You have been arrested");
        }
    }
    updateCrimeUi();
    updateBankUi();
}

void MainWindow::on_commitRobberyButton_clicked()
{
    if(player.isFree() && !player.isSick()) {
        if(bank.earn(crime.commitRobbery())) {
            updateNoticeBoard("You are getting better at this");
        }else {
            player.setFree(false);
            updateNoticeBoard("You have been arrested");
        }
    }
    updateCrimeUi();
    updateBankUi();
}

void MainWindow::on_commitBankFraudButton_clicked()
{
    if(player.isFree() && !player.isSick()) {
        if(bank.earn(crime.commitBankFraud())) {
            updateNoticeBoard("You are getting better at this");
        }else {
            player.setFree(false);
            updateNoticeBoard("You have been arrested");
        }
    }
    updateCrimeUi();
    updateBankUi();
}

//crime control ends

//start station control


void MainWindow::on_getBailButton_clicked()
{
    if(!player.isFree()) {
        if(station.getBail(bank.spend(station.getBailAmount()))) {
            player.setFree(true);
            updateNoticeBoard("Bail was Successfull");
        }else {
            updateNoticeBoard("Failed make sure you have the bail fee");
        }
    }else {
        updateNoticeBoard("you are not in prison");
    }

    updateStationUi();
    updateBankUi();
}

//Station control ends

//Expenses Control start

void MainWindow::on_buyAHouse_clicked()
{
    if(expenses.getRenting()) {
        updateNoticeBoard("You dont own this house");
    }else if(expenses.hasHouse() && !expenses.getMortgaging()) {
        if(bank.earn(expenses.sellHouse())) {
            updateNoticeBoard("House sold");
        }else {
            updateNoticeBoard("house not sold");
        }
    }else {
        if(expenses.buyHouse(bank.spend(expenses.getHouseCost()))) {
            updateNoticeBoard("House bought");
        }else {
            updateNoticeBoard("ensure you have sufficient cash");
        }
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_hireThugs_clicked()
{
    if(expenses.hasThugs()) {
        if(expenses.dismissThugs(bank.spend(expenses.getThugSalary()))) {
            updateNoticeBoard("You paid off your thugs");
        }else {
            updateNoticeBoard("ensure you have sufficient cash to pay them off");
        }
    }else {
        if(expenses.hireThugs()) {
            updateNoticeBoard("Have hired Some thugs now go do the dirty work");
        }else {
            updateNoticeBoard("this should never show");
        }
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_buyACar_clicked()
{
    if(expenses.hasCar()) {
        if(bank.earn(expenses.sellCar())) {
            updateNoticeBoard("The Car has been Sold");
        }
    }else {
        if(expenses.buyCar(bank.spend(expenses.getCarCost()))) {
            updateNoticeBoard("The Car has been bought");
        }else {
            updateNoticeBoard("Failed");
        }
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_hireALawyer_clicked()
{
    if(expenses.hasLawyer()) {
        if(expenses.dismissLawyer(bank.spend(expenses.getLawyerSalary()))) {
            updateNoticeBoard("You paid off your lawyer");
        }else {
            updateNoticeBoard("ensure you have sufficient cash to pay off you lawyer");
        }
    }else {
        if(expenses.hireLawyer()) {
            updateNoticeBoard("You have the law on your side now");
        }else {
            updateNoticeBoard("this should never show");
        }
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_hireBodyGuard_clicked()
{
    if(expenses.hasBodyGuard()) {
        if(expenses.dismissBodyGuard(bank.spend(expenses.getBodyGuardSalary()))) {
            updateNoticeBoard("You paid off your body Gaurd");
        }else {
            updateNoticeBoard("ensure you have sufficient cash to pay them off");
        }
    }else {
        if(expenses.hireBodyGuard()) {
            updateNoticeBoard("You security is being taken care of just got a body guard");
        }else {
            updateNoticeBoard("this should never show");
        }
    }
    updateExpensesUi();
    updateStationUi();
    updateBankUi();
}



void MainWindow::on_consumePotatoes_clicked()
{
    if(player.eatPotatoes(kitchen.buyPotatoes(bank.spend(kitchen.getPotatoCost())))) {
        updateNoticeBoard("That was a delicious one");
    }else{
        updateNoticeBoard("Too broke to eat");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}



void MainWindow::on_consumeCarrot_clicked()
{
    if(player.eatCarrots(kitchen.buyCarrot(bank.spend(kitchen.getCarrotCost())))) {
        updateNoticeBoard("Some crunchy carrot right there");
    }else{
        updateNoticeBoard("that carrot is for who can pay");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}

void MainWindow::on_energyDrink_clicked()
{
    if(player.energyDrink(kitchen.energyDrink(bank.spend(kitchen.getEnergyDrinkCost())))) {
        updateNoticeBoard("Hmm thats refreshing");
    }else{
        updateNoticeBoard("Such drinks don't fall from nowhere");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}

void MainWindow::on_consumeBeans_clicked()
{
    if(player.eatRice(kitchen.buyRice(bank.spend(kitchen.getRiceCost())))) {
        updateNoticeBoard("Ewa of life");
    }else{
        updateNoticeBoard("we used money to prepare that so pay");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}

void MainWindow::on_consumeSpagetti_clicked()
{
    if(player.eatSpaghetti(kitchen.buySpagetti(bank.spend(kitchen.getSpagettiCost())))) {
        updateNoticeBoard("Now thats what i call Spagetti");
    }else{
        updateNoticeBoard("that spagetti is too good for your cash");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}

void MainWindow::on_consumeRice_clicked()
{
    if(player.eatRice(kitchen.buyRice(bank.spend(kitchen.getRiceCost())))) {
        updateNoticeBoard("i love this");
    }else{
        updateNoticeBoard("that food would have to wait go work for money");
    }
    updateKitchenUi();
    updateBankUi();
    updateProgressUi();
}


void MainWindow::on_goldBuyButton_clicked()
{
    if(stock.buyGold(bank.spend(stock.getGoldPrice()))) {
        updateNoticeBoard("You have bought into the gold market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_goldSellButton_clicked()
{
    if(bank.earn(stock.sellGold())) {
        updateNoticeBoard("You sold your gold");
    }else {
        updateNoticeBoard("you have no gold to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_bronzeBuyButton_clicked()
{
    if(stock.buyBronze(bank.spend(stock.getBronzePrice()))) {
        updateNoticeBoard("You have bought into the bronze market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_bronzeSellButton_clicked()
{
    if(bank.earn(stock.sellBronze())) {
        updateNoticeBoard("You sold your bronze");
    }else {
        updateNoticeBoard("you have no bronze to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_oilBuyButton_clicked()
{
    if(stock.buyCrude(bank.spend(stock.getCrudePrice()))) {
        updateNoticeBoard("You have bought into the oil market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
}

void MainWindow::on_oilSellButton_clicked()
{
    if(bank.earn(stock.sellCrude())) {
        updateNoticeBoard("You sold your Oil");
    }else {
        updateNoticeBoard("you have no oil to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_ironBuyButton_clicked()
{
    if(stock.buyIron(bank.spend(stock.getIronPrice()))) {
        updateNoticeBoard("You have bought into the iron market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_ironSellButton_clicked()
{
    if(bank.earn(stock.sellIron())) {
        updateNoticeBoard("You sold your iron");
    }else {
        updateNoticeBoard("you have no iron to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_platinumBuyButton_clicked()
{
    if(stock.buyPlatinum(bank.spend(stock.getPlatinumPrice()))) {
        updateNoticeBoard("You have bought into the platinium market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_platinumSellButton_clicked()
{
    if(bank.earn(stock.sellPlatinum())) {
        updateNoticeBoard("You sold your Platinum");
    }else {
        updateNoticeBoard("you have no iron to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_silverBuyButton_clicked()
{
    if(stock.buySilver(bank.spend(stock.getSilverPrice()))) {
        updateNoticeBoard("You have bought into the silver market");
    }else {
        updateNoticeBoard("You do not have enough cash");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_silverSellButton_clicked()
{
    if(bank.earn(stock.sellSilver())) {
        updateNoticeBoard("You sold your Silver");
    }else {
        updateNoticeBoard("you have no iron to sell");
    }
    updateStockUi();
    updateBankUi();
}

void MainWindow::on_takeAPillButton_clicked()
{
    if(player.takePill(clinic.buyPill(bank.spend(clinic.getPillCost())))) {
        updateNoticeBoard("You just took a pill hope you get better soon");
    }else {
        updateNoticeBoard("You need money to take treatment");
    }
    updateBankUi();
    updateClinicUi();
    updateProgressUi();
}

void MainWindow::on_takeAShotButton_clicked()
{
    if(player.takeInjection(clinic.buyInjection(bank.spend(clinic.getInjectionCost())))) {
        updateNoticeBoard("You just took a shot hope you get better soon");
    }else {
        updateNoticeBoard("You need money to take treatment");
    }
    updateBankUi();
    updateClinicUi();
    updateProgressUi();
}

void MainWindow::on_payHospitalBillButton_clicked()
{
    if(player.isSick()) {
        if(player.hospitalDischarge(clinic.payHospitalBill(bank.spend(clinic.getHospitalBill())))) {
            updateNoticeBoard("You have been discharged");
        }else {
            updateNoticeBoard("You need money to take treatment");
        }
    }else {
        updateNoticeBoard("You are not sick");
    }

    updateBankUi();
    updateClinicUi();
    updateProgressUi();
}

void MainWindow::on_doCheckupButton_clicked()
{
    if(player.doCheckUp(clinic.payCheckup(bank.spend(clinic.getCheckupBill())))) {
        updateNoticeBoard("You did a medical checkup please keep it up");
    }else {
        updateNoticeBoard("You need money to take treatment");
    }
    updateBankUi();
    updateClinicUi();
    updateProgressUi();
}

void MainWindow::on_HireANurseButton_clicked()
{
    if(expenses.hasNurse()) {
        if(expenses.dismissNurse(bank.spend(expenses.getNurseSalary()))) {
            updateNoticeBoard("You have fired your nurse");
        }else {
            updateNoticeBoard("You will need to payoff your nurse");
        }
    }else {
        if(expenses.hireNurse()) {
            updateNoticeBoard("You have hired a nurse");
        }
    }
    updateBankUi();
    updateClinicUi();
    updateProgressUi();
}




void MainWindow::on_washHandButton_clicked()
{
    if(player.washHand(bank.spend(grooming.getWashHandCost()))) {
        updateNoticeBoard("those hands are good to go");
    }else {
        updateNoticeBoard("you need money to buy soap");
    }
    updateBankUi();
    updateGroomingUi();
    updateProgressUi();
}

void MainWindow::on_brushTeethButton_clicked()
{
    if(player.brushTeeth(bank.spend(grooming.getBrushCost()))) {
        updateNoticeBoard("You teeths are looking clean");
    }else {
        updateNoticeBoard("No toothpaste to use");
    }
    updateBankUi();
    updateGroomingUi();
    updateProgressUi();
}

void MainWindow::on_takeBathButton_clicked()
{
    if(player.takeBath(bank.spend(grooming.getBathCost()))) {
        updateNoticeBoard("Looking good and ready for a long day");
    }else {
        updateNoticeBoard("Those water bills aren't going to pay themselves");
    }
    updateBankUi();
    updateGroomingUi();
    updateProgressUi();
}

void MainWindow::on_doLaundryButton_clicked()
{
    if(player.doLaundry(bank.spend(grooming.getLaundryCost()))) {
        updateNoticeBoard("cloths are looking clean");
    }else {
        updateNoticeBoard("The machine needs fixing");
    }
    updateBankUi();
    updateGroomingUi();
    updateProgressUi();
}

void MainWindow::on_collectSchoolLoanButton_clicked()
{
    if(bank.getSchoolLoan() == 0.0) {
        if(bank.earn(bank.collectSchoolLoan())) {
            updateNoticeBoard("You have collected a credit worth $"+QString::number(bank.getSchoolLoan()));
        }
    }else {
        updateNoticeBoard("You have outstanding credit dept of $"+QString::number(bank.getSchoolLoan()) );
    }
    updateBankUi();
}

void MainWindow::on_rentAHouse_clicked()
{
    if(expenses.getMortgaging()) {
        updateNoticeBoard("You are unable to rent this house please ensure you don't already own it");
    }else if(expenses.getRenting()) {
        if(bank.spend(expenses.getHouseRent())) {
            if(expenses.stopRentingHouse()) {
                updateNoticeBoard("You moved out of the house");
            }else {
                qDebug() << "rentAHouseFunction failed" << endl;
            }
        }else {

        }
    }else if(expenses.rentAHouse()){
        updateNoticeBoard("You are now renting the house @ $" + QString::number(expenses.getHouseRent()));
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_aquireOnMotgageButton_clicked()
{
    if(expenses.getMortgaging()) {
        updateNoticeBoard("You are already in a mortgage contract with the buyer");
    }else if(expenses.getRenting()) {
        updateNoticeBoard("You are renting this house please terminate that contract before initiating another");
    }else {
        if(bank.spend(expenses.getHouseMotgageDownPayment())){
            if(expenses.initiateMortgageContract()) {
                updateNoticeBoard("You have started the mortgage and would be charged $"
                                  +QString::number(expenses.getMotgageCyclePayment()));

            }else {
                qDebug() << "aquireMortgage Function failed" << endl;
            }
        }else {
            updateNoticeBoard("you do not have sufficient cash for down payment");
        }
    }
    updateExpensesUi();
    updateBankUi();
}

void MainWindow::on_applyingLabourerJob_clicked()
{
    if(job.applyLabouringJob()) {
        updateNoticeBoard("you application has been noted you will get a job soon");
    }else if(job.cancelLabouringJobApplication()) {
        updateNoticeBoard("you have cancelled your application");
    }else {
        updateNoticeBoard("You can't Perfom multile Job at same time");
    }
    updateJobUi();
}

void MainWindow::on_learnBricklayerJob_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }

    if(job.startBrickLayingTraining()) {
        updateNoticeBoard("you have started you training on brick laying");
    }else if(job.stopBrickLayingTraining()) {
        updateNoticeBoard("you have stoped you training on brick laying");
    }else {
        updateNoticeBoard("Training failed to start, make sure you are not doing any other job");
    }
    updateJobUi();
}

void MainWindow::on_applyBrickLayerJob_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }
    if(job.getBrickLayingSkillProgress() >= 100) {
        if(job.applyBrickLayingJob()) {
            updateNoticeBoard("Your Application is pending");
        }else if(job.cancelBrickLayingJobApplication()) {
            updateNoticeBoard("you have cancelled your application");
        }else {
            updateNoticeBoard("You cant Perfome multible jobs at same time");
        }
    }else {
        updateNoticeBoard("You don't have the required skill");
    }

    updateJobUi();
}

void MainWindow::on_startPoliceOfficerTraining_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }
    if(job.startPoliceTraining()) {
        updateNoticeBoard("you have started your training in the police Academy");
    }else if(job.stopPoliceTraining()) {
        updateNoticeBoard("you have abscornded from the police academy");
    }else {
        updateNoticeBoard("Training failed to start, make sure you are not doing any other job");
    }
    updateJobUi();
}

void MainWindow::on_applyPoliceOfficerJob_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }
    if(job.getPoliceOfficerSkillProgress() >= 100) {
        if(job.applyPoliceJob()) {
            updateNoticeBoard("Your Application is pending");
        }else if(job.cancelPoliceJobApplication()) {
            updateNoticeBoard("you have cancelled your application");
        }else {
            updateNoticeBoard("You cant Perfome multible jobs at same time");
        }
    }else {
        updateNoticeBoard("You can't work as a police officer without training");
    }

    updateJobUi();
}

void MainWindow::on_startDoctorsTraining_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }
    if(job.startDoctorsTraining()) {
        updateNoticeBoard("you have started your training in the Medical College");
    }else if(job.stopDoctorsTraining()) {
        updateNoticeBoard("you withdrew from college");
    }else {
        updateNoticeBoard("Training failed to start, make sure you are not doing any other job");
    }

    updateJobUi();
}

void MainWindow::on_applyDoctorsJob_clicked()
{
    if(!expenses.hasHouse()) {
        updateNoticeBoard("You need to get a house first please rent a house");
        return;
    }
    if(job.getDoctorSkillProgress() >= 100) {
        if(job.applyDoctorJob()) {
            updateNoticeBoard("Your Application is pending");
        }else if(job.cancelDoctorJobApplication()) {
            updateNoticeBoard("you have cancelled your application");
        }else {
            updateNoticeBoard("You cant Perfome multible jobs at same time");
        }
    }else {
        updateNoticeBoard("Medical jobs require certification");
    }

    updateJobUi();
}
