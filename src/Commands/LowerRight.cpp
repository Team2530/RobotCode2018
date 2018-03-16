#include "LowerRight.h"
#include "Robot.h"
#include "Subsystems/Ramp.h"

LowerRight::LowerRight() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowerRight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowerRight::Execute() {
	Robot::ramp->LowerRight();
}

// Make this return true when this Command no longer needs to run execute()
bool LowerRight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LowerRight::End() {
	Robot::ramp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerRight::Interrupted() {
	Robot::ramp->Stop();
}
