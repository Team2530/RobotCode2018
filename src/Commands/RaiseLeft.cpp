#include "RaiseLeft.h"

RaiseLeft::RaiseLeft() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RaiseLeft::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseLeft::Execute() {
	Robot::ramp->RaiseLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RaiseLeft::End() {
	Robot::ramp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseLeft::Interrupted() {
	Robot::ramp->Stop();
}
