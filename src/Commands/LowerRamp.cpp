#include "LowerRamp.h"
#include "Robot.h"
#include "Subsystems/Ramp.h"

LowerRamp::LowerRamp() {
	Requires(Robot::ramp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void LowerRamp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LowerRamp::Execute() {
	Robot::ramp->Lower();
}

// Make this return true when this Command no longer needs to run execute()
bool LowerRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LowerRamp::End() {
	Robot::ramp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerRamp::Interrupted() {
	Robot::ramp->Stop();
}
