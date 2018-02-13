#include "DriveInches.h"

DriveInches::DriveInches(double distance) {
		Robot::drivetrain->DriveStraightAuto(distance);
		// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveInches::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveInches::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveInches::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveInches::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInches::Interrupted() {

}
