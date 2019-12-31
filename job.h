#ifndef JOB_H
#define JOB_H


class Job
{
public:
    Job();

private:
    bool working;
    bool applyingLabourer;
    bool applyingBrickLaying;
    bool applyingPoliceOfficer;
    bool applyingDoctorJob;
    bool learningBrickLaying;
    bool learningPoliceOfficer;
    bool learningDoctor;
    double brickLayingTuitionFee;
    double policeOfficerTuitionFee;
    double doctorTuitionFee;
    int brickLayingSkillProgress;
    int policeOfficerSkillProgress;
    int
};

#endif // JOB_H
