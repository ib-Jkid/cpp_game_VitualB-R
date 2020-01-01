#include "job.h"

Job::Job(QObject *parent) : QObject(parent)
{

    workCycle = 0;
    missed = 0;
    workingAslabourer = false;
    workingAsBrickLayer = false;
    workingAsPoliceOfficer = false;
    workingAsDoctor = false;

    applyingLabourer = false;
    applyingBrickLaying = false;
    applyingPoliceOfficer = false;
    applyingDoctorJob = false;

    learningBrickLaying = false;
    learningPoliceOfficer = false;
    learningDoctor = false;

    labourerWorkCycle = 1;
    brickLayerWorkCycle = 3;
    policeOfficerWorkCycle = 6;
    doctorWorkCycle = 10;

    brickLayerTrainingCycle = 20;
    policeOfficerTrainingCycle = 30;
    doctorTrainingCycle = 60;

    brickLayingTuitionFee = 5.0;
    policeOfficerTuitionFee = 15.0;
    doctorTuitionFee = 25.0;

    brickLayingSkillProgress = 100;
    policeOfficerSkillProgress = 100;
    doctorSkillProgress = 0;

    labourerSalary = 50.0;
    brickLayingSalary = 100.0;
    policeOfficerSalary = 300.0;
    doctorSalary = 1200;
}

bool Job::isWorking()
{
    if(
            workingAsDoctor ||
            workingAslabourer ||
            workingAsBrickLayer ||
            workingAsPoliceOfficer ||
            learningDoctor ||
            learningBrickLaying ||
            learningPoliceOfficer||
            applyingLabourer ||
            applyingDoctorJob||
            applyingBrickLaying||
            applyingPoliceOfficer
            )return true;
    return false;
}

void Job::gameCycle()
{
    if(workingAsDoctor) {
        emit on_paySalary(doctorSalary);
        workCycle++;
        if(workCycle == doctorWorkCycle) {
            reset();
        }
    }else if(workingAslabourer) {
        emit on_paySalary(labourerSalary);
        workCycle++;
        if(workCycle == labourerWorkCycle) {
            reset();
        }
    }else if(workingAsBrickLayer) {
        emit on_paySalary(brickLayingSalary);
        workCycle++;
        if(workCycle == brickLayerWorkCycle) {
            reset();
        }
    }else if(workingAsPoliceOfficer) {
        emit on_paySalary(policeOfficerSalary);
        workCycle++;
        if(workCycle == policeOfficerWorkCycle) {
            reset();
        }
    }else if(learningDoctor) {
        if(missed >= 3) reset();
        emit on_payTuitionFee(doctorTuitionFee);

    }else if(learningBrickLaying) {
        if(missed >= 3) reset();
        emit on_payTuitionFee(brickLayingTuitionFee);
    }else if(learningPoliceOfficer) {
        if(missed >= 3) reset();
        emit on_payTuitionFee(policeOfficerTuitionFee);
    }else if(applyingLabourer) {
        reset();
        workingAslabourer = true;
    }else if(applyingBrickLaying) {
        reset();
        workingAsBrickLayer = true;
    }else if(applyingPoliceOfficer) {
        reset();
        workingAsPoliceOfficer = true;
    }else if(applyingDoctorJob) {
        reset();
        workingAsDoctor = true;
    }
}

void Job::tutionFeePaid(bool paid)
{

    if(paid) {
        if(learningDoctor) {
            workCycle++;
            doctorSkillProgress = (workCycle  * 100 / doctorTrainingCycle);
            if(workCycle >= doctorTrainingCycle) {
                reset();
            }
        }else if(learningBrickLaying) {
            workCycle++;
            brickLayingSkillProgress = (workCycle * 100 / brickLayerTrainingCycle );
            if(workCycle >= brickLayerTrainingCycle) {
                reset();
            }
        }else if(learningPoliceOfficer) {
            workCycle++;
            policeOfficerSkillProgress = (workCycle  * 100 / policeOfficerTrainingCycle);
            if(workCycle >= policeOfficerTrainingCycle) {
                reset();
            }
        }
    }else {
        missed++;
    }

}

bool Job::startPoliceTraining()
{
    if(isWorking()) {
        return false;
    }
        reset();
       return  learningPoliceOfficer = true;


}

bool Job::startDoctorsTraining()
{
    if(isWorking()) {
        return false;
    }
        reset();
       return  learningDoctor = true;
}

bool Job::startBrickLayingTraining()
{
    if(isWorking()) {
        return false;
    }
    reset();
    return learningBrickLaying = true;

}

bool Job::applyLabouringJob()
{
    if(isWorking()) {
        return false;
    }
    reset();
    return applyingLabourer = true;
}

bool Job::applyBrickLayingJob()
{
    if(isWorking()) {
        return false;
    }else if(brickLayingSkillProgress >= 100) {
        reset();
        return applyingBrickLaying = true;
    }
    return false;

}

bool Job::applyPoliceJob()
{
    if(isWorking()) {
        return false;
    }
    reset();
    return applyingPoliceOfficer = true;
}

bool Job::applyDoctorJob()
{
    if(isWorking()) {
        return false;
    }
    reset();
    return applyingDoctorJob = true;
}

bool Job::cancelLabouringJobApplication()
{
    if(applyingLabourer) {
        reset();
        return true;
    }
    return false;
}

bool Job::cancelBrickLayingJobApplication()
{
    if(applyingBrickLaying) {
        reset();
        return true;
    }
    return false;
}

bool Job::cancelPoliceJobApplication()
{
    if(applyingPoliceOfficer) {
        reset();
        return true;
    }
    return false;
}

bool Job::cancelDoctorJobApplication()
{
    if(applyDoctorJob()) {
        reset();
        return true;
    }
    return false;
}

bool Job::stopBrickLayingTraining()
{
    if(learningBrickLaying) {
        reset();
        brickLayingSkillProgress = 0;
        return true;
    }
    return false;
}

bool Job::stopPoliceTraining()
{
    if(learningPoliceOfficer) {
        reset();
        policeOfficerSkillProgress = 0;
        return true;
    }
    return false;
}

bool Job::stopDoctorsTraining()
{
    if(learningDoctor) {
        reset();
        doctorSkillProgress = 0;
        return true;
    }
    return false;
}

bool Job::getWorkingAslabourer() const
{
    return workingAslabourer;
}

bool Job::getWorkingAsBrickLayer() const
{
    return workingAsBrickLayer;
}

bool Job::getWorkingAsDoctor() const
{
    return workingAsDoctor;
}

bool Job::getApplyingLabourer() const
{
    return applyingLabourer;
}

bool Job::getApplyingDoctorJob() const
{
    return applyingDoctorJob;
}

bool Job::getApplyingPoliceOfficer() const
{
    return applyingPoliceOfficer;
}

bool Job::getApplyingBrickLaying() const
{
    return applyingBrickLaying;
}

bool Job::getLearningBrickLaying() const
{
    return learningBrickLaying;
}

bool Job::getLearningPoliceOfficer() const
{
    return learningPoliceOfficer;
}

bool Job::getLearningDoctor() const
{
    return learningDoctor;
}

int Job::getBrickLayingSkillProgress() const
{
    return brickLayingSkillProgress;
}

int Job::getPoliceOfficerSkillProgress() const
{
    return policeOfficerSkillProgress;
}

int Job::getDoctorSkillProgress() const
{
    return doctorSkillProgress;
}

bool Job::getWorkingAsPoliceOfficer() const
{
    return workingAsPoliceOfficer;
}

void Job::reset()
{
    workCycle = 0;
    missed = 0;
    workingAslabourer = false;
    workingAsBrickLayer = false;
    workingAsPoliceOfficer = false;
    workingAsDoctor = false;

    applyingLabourer = false;
    applyingBrickLaying = false;
    applyingPoliceOfficer = false;
    applyingDoctorJob = false;

    learningBrickLaying = false;
    learningPoliceOfficer = false;
    learningDoctor = false;

}
