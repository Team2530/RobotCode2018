#include "ResetRamps.h"

ResetRamps::ResetRamps() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::ramp.get());
}

// Called just before this Command runs the first time
void ResetRamps::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ResetRamps::Execute() {
	Robot::ramp->Reset();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetRamps::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ResetRamps::End() {
	Robot::ramp->ReleaseStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetRamps::Interrupted() {
	Robot::ramp->Stop();
}
