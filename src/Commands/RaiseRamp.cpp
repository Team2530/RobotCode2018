#include "RaiseRamp.h"

RaiseRamp::RaiseRamp() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RaiseRamp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseRamp::Execute() {
	Robot::ramp->Raise();
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RaiseRamp::End() {
	Robot::ramp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseRamp::Interrupted() {
	Robot::ramp->Stop();
}
