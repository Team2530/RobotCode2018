#include "DriveInches.h"

DriveInches::DriveInches(double distance) {
		//Robot::drivetrain->DriveStraightAuto(distance);
		// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
    d = distance;
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveInches::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveInches::Execute() {
	d = d*(360/(pi*diameter));//WE MUST CHECK THIS GWUYS ticks = inches*(360/circumference)
	double startingDistance = Robot::drivetrain->GetEncoderDistance();
	if(d<0){
		while((Robot::drivetrain->GetEncoderDistance()-startingDistance)>d){
			double power = maxPower*((Robot::drivetrain->GetEncoderDistance()-startingDistance)/d);
			Robot::drivetrain->DriveStraight(power); //MAY NEED TO GET RID OF POWER FUNCTION THING!!
		}
	}
	else{
		while((Robot::drivetrain->GetEncoderDistance()-startingDistance)<d){
			double power = maxPower*((Robot::drivetrain->GetEncoderDistance()-startingDistance)/d);
			Robot::drivetrain->DriveStraight(power); //MAY NEED TO GET RID OF POWER FUNCTION THING!!
		}

	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveInches::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveInches::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInches::Interrupted() {
	Robot::drivetrain->Stop();
}
