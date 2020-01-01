#ifndef JOB_H
#define JOB_H

#include <QObject>
#include <QDebug>
class Job : public QObject
{
    Q_OBJECT
public:
    explicit Job(QObject *parent = nullptr);
    bool isWorking();

    void gameCycle();

    double getSalary();

    void tutionFeePaid(bool paid);

    bool startPoliceTraining();
    bool startDoctorsTraining();
    bool startBrickLayingTraining();

    bool applyLabouringJob();
    bool applyBrickLayingJob();
    bool applyPoliceJob();
    bool applyDoctorJob();

    bool cancelLabouringJobApplication();
    bool cancelBrickLayingJobApplication();
    bool cancelPoliceJobApplication();
    bool cancelDoctorJobApplication();

    bool stopBrickLayingTraining();
    bool stopPoliceTraining();
    bool stopDoctorsTraining();

    bool getWorkingAslabourer() const;

    bool getWorkingAsBrickLayer() const;

    bool getWorkingAsDoctor() const;

    bool getApplyingLabourer() const;

    bool getApplyingDoctorJob() const;

    bool getApplyingPoliceOfficer() const;

    bool getApplyingBrickLaying() const;

    bool getLearningBrickLaying() const;

    bool getLearningPoliceOfficer() const;

    bool getLearningDoctor() const;

    int getBrickLayingSkillProgress() const;

    int getPoliceOfficerSkillProgress() const;

    int getDoctorSkillProgress() const;

    bool getWorkingAsPoliceOfficer() const;

signals:
    void on_payTuitionFee(double fee);

void on_paySalary(double salary);


private:
    int workCycle;
    int missed;
    bool workingAslabourer;
    bool workingAsBrickLayer;
    bool workingAsPoliceOfficer;
    bool workingAsDoctor;

    bool applyingLabourer;
    bool applyingBrickLaying;
    bool applyingPoliceOfficer;
    bool applyingDoctorJob;

    bool learningBrickLaying;
    bool learningPoliceOfficer;
    bool learningDoctor;

    int labourerWorkCycle;
    int brickLayerWorkCycle;
    int policeOfficerWorkCycle;
    int doctorWorkCycle;

    int brickLayerTrainingCycle;
    int policeOfficerTrainingCycle;
    int doctorTrainingCycle;

    double brickLayingTuitionFee;
    double policeOfficerTuitionFee;
    double doctorTuitionFee;

    double labourerSalary;
    double brickLayingSalary;
    double policeOfficerSalary;
    double doctorSalary;

    int brickLayingSkillProgress;
    int policeOfficerSkillProgress;
    int doctorSkillProgress;

    void reset();
};

#endif // JOB_H
