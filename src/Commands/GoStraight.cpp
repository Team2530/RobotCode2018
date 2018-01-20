#include "GoStraight.h"

GoStraight::GoStraight() {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void GoStraight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GoStraight::Execute() {
	Robot::drivetrain->DriveStraight();
}

// Make this return true when this Command no longer needs to run execute()
bool GoStraight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GoStraight::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoStraight::Interrupted() {
	Robot::drivetrain->Stop();
}
