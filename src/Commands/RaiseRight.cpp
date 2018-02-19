#include "RaiseRight.h"

RaiseRight::RaiseRight() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RaiseRight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseRight::Execute() {
	Robot::ramp->RaiseRight();

}

// Make this return true when this Command no longer needs to run execute()
bool RaiseRight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RaiseRight::End() {
	Robot::ramp->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseRight::Interrupted() {
	Robot::ramp->Stop();

}
