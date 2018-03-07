#include "DriveInches.h"

DriveInches::DriveInches(double distance) {
		// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	d = distance*ticksPerInch;//WE MUST CHECK THIS GWUYS ticks = inches*(360/circumference)
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveInches::Initialize() {
	double startingDistance = Robot::drivetrain->GetEncoderDistance();
	target = startingDistance + d;
	//rotations = d/circumference;
	//double power;

}

// Called repeatedly when this Command is scheduled to run
void DriveInches::Execute() {


		Robot::drivetrain->DriveStraight(target); //?????????//MAY NEED TO GET RID OF POWER FUNCTION THING!!
		SmartDashboard::PutNumber("d:  ", d);
		SmartDashboard::PutNumber("target:  ", target);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveInches::IsFinished() {
	if(abs(target-Robot::drivetrain->GetEncoderDistance())<buffer){
		return true;
	}
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
